// 백준알고리즘 15686번 :: 치킨 배달
#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chiken;
vector<pair<int, int>> selected_chiken;
int map[51][51];
int N, M;
int ans = -1;

// 치킨거리를 구하는 함수
int calculate_chikendistance()
{
	int distance = 0;
	for (size_t i = 0; i < house.size(); i++)
	{
		int house_x = house[i].first;
		int house_y = house[i].second;

		int local_distance = abs(house_x - selected_chiken[0].first) + abs(house_y - selected_chiken[0].second);
		for (size_t j = 1; j < selected_chiken.size(); j++)
		{
			int new_distance = abs(house_x - selected_chiken[j].first) + abs(house_y - selected_chiken[j].second);
			if (local_distance > new_distance) local_distance = new_distance;
		}
		distance += local_distance;
	}
	return distance;
}

// start : chiken vector 시작 index
// count : M개까지 선택하기 위한 count
// 치킨집 M개를 선택하기 위한 함수
void select_chiken(int start, int count)
{
	// M개 선택했으면 치킨 거리를 구한다.
	if (count == M)
	{
		int lcans = calculate_chikendistance();
		if (lcans < ans || ans == -1) ans = lcans;
		return;
	}

	for (size_t i = start; i < chiken.size(); i++)
	{
		selected_chiken.push_back(chiken[i]);
		select_chiken(i+1, count+1);
		selected_chiken.pop_back();
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			// 집
			if (map[i][j] == 1) house.push_back(make_pair(i, j));
			// 치킨집
			else if (map[i][j] == 2) chiken.push_back(make_pair(i, j));
		}
	}

	for (size_t i = 0; i <= chiken.size()-M; i++)
	{
		selected_chiken.push_back(chiken[i]);
		select_chiken(i+1, 1);
		selected_chiken.pop_back();
	}

	cout << ans;

	return 0;
}
