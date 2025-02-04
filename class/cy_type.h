#pragma once
#include <vector>
#include <memory>
#include <iostream>

class Node {
public:
    int id;
    double value;
    std::vector<std::shared_ptr<class Edge>> edges;

    Node(int id, double value = 0.0);
    virtual ~Node() = default;

    void addEdge(std::shared_ptr<Edge> edge);
    virtual void compute() = 0; // 순수 가상 함수 (연산 노드에서 구현)

};

class AddNode : public Node {
public:
    AddNode(int id);
    void compute() override;
};

Node::Node(int id, double value) : id(id), value(value) {}

void Node::addEdge(std::shared_ptr<Edge> edge) {
    edges.push_back(edge);
}

AddNode::AddNode(int id) : Node(id) {}

void AddNode::compute() {
    value = 0;
    for (auto& edge : edges) {
        value += edge->from->value;
    }
}

MulNode::MulNode(int id) : Node(id) {}
void MulNode::compute() {
    value = 1;
    for (auto& edge : edges) {
        value *= edge->from->value;
    }
}
class AddNode : public Node {
public:
    AddNode(int id);
    void compute() override;
};
class MulNode : public Node {
public:
    MulNode(int id);
    void compute() override;
};



class Edge {
public:
    std::shared_ptr<Node> from;
    std::shared_ptr<Node> to;
    double weight;

    Edge(std::shared_ptr<Node> from, std::shared_ptr<Node> to, double weight = 1.0);
    void print() const;
};

Edge::Edge(std::shared_ptr<Node> from, std::shared_ptr<Node> to, double weight)
    : from(from), to(to), weight(weight) {}

void Edge::print() const {
    std::cout << "  Edge from " << from->id << " to " << to->id << " (Weight: " << weight << ")\n";
}