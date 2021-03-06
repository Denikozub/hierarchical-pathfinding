#include "node.h"

Node::Node(double lat, double lon) : lat(lat), lon(lon) {}

double Node::get_lat() const {
    return this->lat;
}

void Node::set_lat(double new_lat) {
    this->lat = new_lat;
}

double Node::get_lon() const {
    return this->lon;
}

void Node::set_lon(double new_lon) {
    this->lon = new_lon;
}

int Node::get_cluster_no() const {
    return this->cluster_no;
}

void Node::set_cluster_no(int new_cluster_no) {
    this->cluster_no = new_cluster_no;
}

bool Node::has_cluster() const {
    return this->cluster_no != -1;
}

void Node::set_outer(bool new_is_outer_) {
    this->is_outer_ = new_is_outer_;
}

bool Node::is_outer() const {
    return this->is_outer_;
}

void Node::reset_cluster_data() {
    this->cluster_no = -1;
    this->is_outer_ = false;
}
