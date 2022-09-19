#pragma once

#include <string>
#include <memory>
#include "date.h"

using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	Or,
	And,
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& date);

	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& value);

	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison cmp_;
	const string value_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> left_node, shared_ptr<Node> right_node);

	bool Evaluate(const Date& date, const string& event) const override;

private:
	const LogicalOperation op_;
	const shared_ptr<Node> left_node_, right_node_;
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
};
