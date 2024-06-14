#ifndef Q2_H
#define Q2_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>


namespace q2 {
    struct Patient {
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };
    std::vector<Patient> read_file(std::string filename);
    void sort(std::vector<Patient>& patients);
};

// implementations
inline std::vector<q2::Patient> q2::read_file(std::string filename) {
    std::vector<Patient> patients;
    // std::cout << "everything is ok until this line" << std::endl;

    std::ifstream file(filename);
    // std::cout << "everything is ok until this line" << std::endl;
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return patients;
    }
    // std::cout << "everything is ok until this line" << std::endl;

    std::string line{};
    std::getline(file, line); 
    std::getline(file, line); 
    // std::cout << "everything is ok until this line" << std::endl;

    while (std::getline(file, line)) {
        std::stringstream iss(line);
        std::string first_name, last_name, age_str, smoke_str, area_q_str, alkhol_str;
        // std::cout << "everything is ok until this line" << std::endl;

        if (std::getline(iss, first_name, ',') && 
            std::getline(iss, last_name, ',') &&
            std::getline(iss, age_str, ',') && 
            std::getline(iss, smoke_str, ',') && 
            std::getline(iss, area_q_str, ',') && 
            std::getline(iss, alkhol_str, ',')) {

            size_t endPos = first_name.find_last_not_of(' ');
            first_name.erase(endPos + 1);
            std::string full_name = first_name + " " + last_name;
            size_t age = std::stoul(age_str);
            size_t smoke = std::stoul(smoke_str);
            size_t area_q = std::stoul(area_q_str);
            size_t alkhol = std::stoul(alkhol_str);

            patients.push_back({full_name, age, smoke, area_q, alkhol});

        }
    }

    file.close();
    return patients;
}

inline bool compare(const q2::Patient& p1, const q2::Patient& p2) {
    size_t p1_val = 3 * p1.age + 5 * p1.smokes + 2 * p1.area_q + 4 * p1.alkhol;
    size_t p2_val = 3 * p2.age + 5 * p2.smokes + 2 * p2.area_q + 4 * p2.alkhol;
    return p1_val > p2_val;
}

inline void q2::sort(std::vector<Patient>& patients) {
    std::sort(patients.begin(), patients.end(), compare);
}

#endif //Q2_H