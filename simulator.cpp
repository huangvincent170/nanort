#include "simulator.hpp"
#include <iostream>


Simulator::Simulator() {
    contextp = new VerilatedContext;
    vinter_obj = new Vintersector{contextp};
    timestamp = 0;
    std::cout << "called constructor!\n";
}


void Simulator::append_to_queue(intersector_input_t input) {
    input_deque.push_back(input);
}

void Simulator::step() {
    if (input_deque.empty()) {
        std::cout << "ERROR: simulator attempted to read form empty input deque\n";
        return;
    }

    intersector_input_t input = input_deque.at(0);
    vinter_obj->min_t = input.min_t;
    vinter_obj->max_t = input.max_t;
    vinter_obj->bmin0 = input.bmin0;
    vinter_obj->bmin1 = input.bmin1;
    vinter_obj->bmin2 = input.bmin2;
    vinter_obj->bmax0 = input.bmax0;
    vinter_obj->bmax1 = input.bmax1;
    vinter_obj->bmax2 = input.bmax2;
    vinter_obj->ray_org0 = input.ray_org0;
    vinter_obj->ray_org1 = input.ray_org1;
    vinter_obj->ray_org2 = input.ray_org2;
    vinter_obj->ray_inv_dir0 = input.ray_inv_dir0;
    vinter_obj->ray_inv_dir1 = input.ray_inv_dir1;
    vinter_obj->ray_inv_dir2 = input.ray_inv_dir2;
    vinter_obj->ray_dir_sign0 = input.ray_dir_sign0;
    vinter_obj->ray_dir_sign1 = input.ray_dir_sign1;
    vinter_obj->ray_dir_sign2 = input.ray_dir_sign2;

    vinter_obj->eval();
    input_deque.pop_front();

    timestamp++;
    // std::cout << "timestamp: " << timestamp << "\n";

    output_deque.push_back(intersector_output_t());
    output_deque.back().tmin = fixed_to_float(vinter_obj->tmin);
    output_deque.back().tmax = fixed_to_float(vinter_obj->tmax);
}

intersector_output_t Simulator::pop_queue() {
    auto val(std::move(output_deque.front()));
    output_deque.pop_front();
    // val now has the object
    return val;
}

uint64_t Simulator::get_timestamp() {
    return timestamp;
}

Simulator::~Simulator() {
    // delete vinter_obj;
    // delete contextp;
}