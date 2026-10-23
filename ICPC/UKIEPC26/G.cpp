#include <bits/stdc++.h>
using namespace std;

struct Pt {
	int x, y;
	Pt() : x(0), y(0) {}
	Pt(int x, int y) : x(x), y(y) {}
};

int cross(Pt a, Pt b, Pt c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
}

int n, m;
vector<Pt> pts;

void solve() {
	cin >> n >> m;
	for (int i = 0, cnt = 0; cnt < n; i++, cnt++) {
		int x, y;
		cin >> x >> y;
		pts.push_back(Pt(x, y));
		while (pts.size() > 2 && cross(pts[i - 2], pts[i - 1], pts[i]) <= 0) {
			pts.erase(--(--pts.end()));
			i--;
		}
	}
	for(int j = 0; j < 10; j++) {
		while (pts.size() > 3 && cross(pts[pts.size() - 2], pts[pts.size() - 1], pts[0]) <= 0) pts.pop_back();
		int ptr = 0;
		vector<Pt> newPts;
		while (pts.size() - ptr > 3 && cross(pts[pts.size() - 1], pts[ptr], pts[ptr + 1]) <= 0) ptr++;
		for (int i = ptr; i < pts.size(); i++) {
			newPts.push_back(pts[i]);
		}
		pts = newPts;
	}

	long double perm = 0;
	for (int i = 0; i < pts.size(); i++) {
		int dx = pts[i].x - pts[(pts.size() + i - 1) % pts.size()].x;
		int dy = pts[i].y - pts[(pts.size() + i - 1) % pts.size()].y;
		perm += sqrt(dx * dx + dy * dy);
	}

	int bottomLeft = 0;
	for (int i = 0; i < pts.size(); i++) {
		Pt p = pts[i];
		if (make_pair(p.y, p.x) < make_pair(pts[bottomLeft].y, pts[bottomLeft].x)) bottomLeft = i;
	}
	int bottomLeftP1 = bottomLeft;
	while (pts[(bottomLeftP1 + 1) % pts.size()].y == 0) bottomLeftP1 = (bottomLeftP1 + 1) % pts.size();
	int dx = pts[bottomLeftP1].x - pts[bottomLeft].x;

	int firstDist = dx;
	bool onGround = bottomLeftP1 != bottomLeft;

	m -= pts[bottomLeft].x;

	long double eps = 1e-7;
	int ans;
	if (onGround) {
		ans = (int) (ceil((m - firstDist + eps) / perm));
		ans = max(ans, 0);
	}
	else {
		ans = (int) (ceil((long double) (m + eps) / perm));
		ans = max(ans, 0);
	}
	cout << ans << endl;

}

int main() {
	cout.precision(20);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}


// 7 4
// 1 0
// 2 1
// 3 0
// 4 1
// 5 0
// 5 5
// 1 5
