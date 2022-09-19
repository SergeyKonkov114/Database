#include "node.h"

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date) {}
bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (cmp_) {
	case Comparison::Less:
		return date < date_;
	case Comparison::LessOrEqual:
		return date <= date_;
	case Comparison::Greater:
		return date > date_;
	case Comparison::GreaterOrEqual:
		return date >= date_;
	case Comparison::Equal:
		return date == date_;
	case Comparison::NotEqual:
		return date != date_;
	}
	return true;
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const std::string& value) : cmp_(cmp), value_(value) {}
bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (cmp_) {
	case Comparison::Less:
		return event < value_;
	case Comparison::LessOrEqual:
		return event <= value_;
	case Comparison::Greater:
		return event > value_;
	case Comparison::GreaterOrEqual:
		return event >= value_;
	case Comparison::Equal:
		return event == value_;
	case Comparison::NotEqual:
		return event != value_;
	}
	return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> left_node, shared_ptr<Node> right_node) :
	op_(op), left_node_(left_node), right_node_(right_node) {}
bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch (op_) {
	case LogicalOperation::And:
		return left_node_->Evaluate(date, event) && right_node_->Evaluate(date, event);
	case LogicalOperation::Or:
		return left_node_->Evaluate(date, event) || right_node_->Evaluate(date, event);
	}
	return true;
}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}