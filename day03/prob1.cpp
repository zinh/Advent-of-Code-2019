#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> read_file(const string&);
vector<struct Point> map_line(const vector<string>&);
vector<string> split_token(const string&, const string&);

struct Point {
  int x, y;
};

void print_line(const vector<struct Point>& line) {
  for (auto point : line)
    cout << '(' << point.x << ',' << point.y << ')' << '\n';
}

string point_to_string(const struct Point& p) {
  return to_string(p.x) + "," + to_string(p.y);
}

vector<struct Point> intersection(const vector<struct Point> line1, const vector<struct Point> line2){
  vector<struct Point> result;
  unordered_map<string, bool> h;
  for (auto p2 : line2)
    h[point_to_string(p2)] = true;
  for (auto p1 : line1)
    if (h[point_to_string(p1)])
      result.push_back(p1);
  return result;
}

int
main(int argc, char** argv){
  string filename {argv[1]};
  vector<string> lines = read_file(filename);
  vector<struct Point> line1 = map_line(split_token(lines[0], ","));
  vector<struct Point> line2 = map_line(split_token(lines[1], ","));
  vector<struct Point> intersections = intersection(line1, line2);
  int min_distance = INT32_MAX;
  for (auto p : intersections){
    int distance = abs(p.x) + abs(p.y);
    if (distance < min_distance)
      min_distance = distance;
  }
  cout << "Result: " << min_distance << '\n';
  return 0;
}

vector<string>
read_file(const string& filename) {
  ifstream is(filename);
  vector<string> vs(2);
  is >> vs[0];
  is >> vs[1];
  
  return vs;
}

vector<struct Point>
map_line(const vector<string>& points) {
  vector<Point> route;
  struct Point current_point = {.x = 0, .y = 0};
  //route.push_back(current_point);
  for (auto point : points) {
    char command = point.at(0);
    int length = stoi(point.substr(1, string::npos));
    for (int i = 0; i < length; i++) {
      switch(command) {
      case 'R':
	current_point.x += 1;
	break;
      case 'L':
	current_point.x -= 1;
	break;
      case 'U':
	current_point.y += 1;
	break;
      case 'D':
	current_point.y -= 1;
	break;
      default:
	throw runtime_error("Invalid character");
      }
      struct Point p {current_point.x, current_point.y};
      route.push_back(p);
    }
  }
  return route;
}

vector<string>
split_token(const string& s, const string& substr) {
  vector<string> v;
  int next_pos, pos = 0;
  while ((next_pos = s.find(substr, pos)) != string::npos) {
    v.push_back(s.substr(pos, next_pos - pos));
    pos = next_pos + 1;
  }
  if (pos < s.size())
    v.push_back(s.substr(pos, string::npos));
  return v;
}
