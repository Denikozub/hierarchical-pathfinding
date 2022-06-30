#include "node.h"

Node::Node(double lat, double lon) : lat(lat), lon(lon) {}

Node::Node(double&& lat, double&& lon) : lat(lat), lon(lon) {}

double Node::get_lat() const {
    return lat;
}

void Node::set_lat(double new_lat) {
    lat = new_lat;
}

double Node::get_lon() const {
    return lon;
}

void Node::set_lon(double new_lon) {
    lon = new_lon;
}

int Node::get_cluster_no() const {
    return cluster_no;
}

void Node::set_cluster_no(int new_cluster_no) {
    cluster_no = new_cluster_no;
}

bool Node::has_cluster() const {
    return cluster_no == -1;
}

void Node::set_outer(bool new_is_outer_) {
    is_outer_ = new_is_outer_;
}

bool Node::is_outer() const {
    return is_outer_;
}

