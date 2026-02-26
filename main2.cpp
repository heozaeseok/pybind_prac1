
#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <iostream>
#include <vector>
using namespace std;
#define endl "\n";

namespace py = pybind11;

int main() {
  py::scoped_interpreter guard{};

  py::module_ sys = py::module_::import("sys");
  sys.attr("path").attr("append")("../python");

  py::module_ m = py::module_::import("act");
  m.attr("run")();

  vector<int> v;
  v.push_back(m.attr("run")().cast<int>());

  for (auto i : v) {
    cout << i << endl;
  }

  return 0;
}