#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define endl "\n";

//conda activate GOPT
//cd C:\Users\USER\Desktop\SDO\pybind_prac\build
//cmake --build . --config Release
//$env:PYTHONHOME = "C:\Users\USER\anaconda3\envs\GOPT"
//$env:PYTHONPATH = "C:\Users\USER\anaconda3\envs\GOPT\Lib;C:\Users\USER\anaconda3\envs\GOPT\Lib\site-packages"
//./Release/main2.exe


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

  py::module_ sys = py::module_::import("sys");
      
  sys.attr("path").attr("append")("C:/Users/USER/Desktop/SDO/pybind_prac/python");
  sys.attr("path").attr("append")("C:/Users/USER/Desktop/SDO/GOPT_cvrp");
  sys.attr("path").attr("append")("C:/Users/USER/Desktop/SDO/GOPT_cvrp/envs/Packing");

  py::module_ checker_no_seq = py::module_::import("py_checker_no_seq");

  for (int i = 0; i < 5; i++) {
    vector<int> route = enterRoute();

    bool check = checker_no_seq.attr("check")(route).cast<bool>();

    if (check) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }

  return 0;
}