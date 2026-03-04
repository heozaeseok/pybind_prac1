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

int main() {
  py::scoped_interpreter guard{};

  try {
    py::module_ sys = py::module_::import("sys");
        
    sys.attr("path").attr("append")("C:/Users/USER/Desktop/SDO/pybind_prac/python");
    sys.attr("path").attr("append")("C:/Users/USER/Desktop/SDO/GOPT_cvrp");

    py::module_ checker = py::module_::import("py_checker");

    for (int i = 0; i < 5; i++) {
      vector<int> route = enterRoute();

      bool check = checker.attr("check")(route).cast<bool>();

      if (check) {
        cout << "true" << endl;
      } else {
        cout << "false" << endl;
      }
    }
  } 
  // 파이썬 에러를 터미널에 출력
  catch (py::error_already_set& e) {
    cerr << "\n[파이썬 에러 발생!]\n" << e.what() << endl;
  } 
  catch (const std::exception& e) {
    cerr << "\n[C++ 에러 발생!]\n" << e.what() << endl;
  }

  return 0;
}