#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Max_City 501
#define Infinity 1e5

typedef int City_ID;
typedef int Weight;

class Line{
public:
	City_ID c1;
	City_ID c2;
	Weight cost;
	Line(City_ID C1, City_ID C2, Weight Cost){
		c1 = C1;
		c2 = C2;
		cost = Cost;
	}
};

vector<Line> lineGood, lineBad;
City_ID root[Max_City];

bool Compare(Line l1, Line l2){
	return l1.cost < l2.cost;
}

City_ID findTheRoot(City_ID i){
	if (root[i] == -1)
		return i;
	City_ID R = findTheRoot(root[i]);
	root[i] = R;
	return R;
}

vector<City_ID> result;
Weight maxCost = 0;
int main(){
	int n, m,status;
	City_ID c1, c2;
	Weight cost;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> c1 >> c2 >> cost >> status;
		Line temp_l = Line(c1,c2,cost);
		if (status == 0)
			lineBad.push_back(temp_l);
		else
			lineGood.push_back(temp_l);
	}
	sort(lineBad.begin(), lineBad.end(), Compare);
	for (City_ID i = 1; i <= n; i++){
		for (City_ID j = 1; j <= n; j++)
			root[j] = -1;
		for (int k = 0; k < lineGood.size(); k++){
			if (lineGood[k].c1 == i || lineGood[k].c2 == i)
				continue;
			City_ID c1 = lineGood[k].c1;
			City_ID c2 = lineGood[k].c2;
			City_ID root1 = findTheRoot(c1);
			City_ID root2 = findTheRoot(c2);
			if (root1 != root2){
				root[root2] = root1;
			}
		}
		Weight cost = 0;
		int num = 0;
		for (City_ID p = 1; p <= n; p++){
			if (p != i && root[p] == -1)
				num++;
		}
		for (int q = 0; q < lineBad.size(); q++){
			if (num == 1)
				break;
			City_ID c1 = lineBad[q].c1, c2 = lineBad[q].c2;
			if (c1 == i || c2 == i)
				continue;
			City_ID root1 = findTheRoot(c1);
			City_ID root2 = findTheRoot(c2);
			if (root1 != root2){
				cost += lineBad[q].cost;
				root[root2] = root1;
				num--;
			}
		}
		if (num > 1){
			cost = Infinity;
		}
		if (cost > 0 && cost > maxCost){
			maxCost = cost;
			result.erase(result.begin(), result.end());
			result.push_back(i);
		}
		else if (cost > 0 && cost == maxCost)
			result.push_back(i);
	}
	if (result.empty())
		cout << "0";
	else{
		for (int i = 0; i < result.size(); i++){
			if (i != 0)
				cout << " ";
			cout << result[i];
		}
	}
	return 0;
}
