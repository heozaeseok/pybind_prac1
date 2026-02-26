#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define endl "\n";

namespace py = pybind11;

vector<int> enterRoute() {
  vector<int> route;
  string line;

  cout << "route : ";
  getline(cin, line);

  stringstream ss(line);
  int r;

  while (ss >> r) {
    route.push_back(r);
  }

  return route;
}

// checker.py와 상호작용 test
int main() {
  py::scoped_interpreter guard{};

  py::module_ sys = py::module_::import("sys");
  sys.attr("path").attr("append")("../python");
  py::module_ checker = py::module_::import("checker");

  // route.push_back(1);
  // route.push_back(2);
  // route.push_back(3);
  // // route = {1, 2, 3};

  for (int i = 0; i < 5; i++) {
    vector<int> route = enterRoute();

    bool check = checker.attr("check")(route).cast<bool>();

    // python에서 전달받은 check(t/f)로 이후 route 연산 수행
    if (check) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }

  return 0;
}