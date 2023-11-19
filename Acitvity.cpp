#include<bits/stdc++.h>
using namespace std;

class Activity {
public:
    char id;
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), compare);

    vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);

    int count = 1;
    int prevFinish = activities[0].finish;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= prevFinish) {
            selectedActivities.push_back(activities[i]);
            prevFinish = activities[i].finish;
            count++;
        }
    }

    cout << "Maximum number of non-overlapping activities: " << count << endl;
    cout << "Selected Activities: ";
    for (auto it : selectedActivities) {
        cout << it.id << " ";
    }
    cout << endl;
}

int main() {
    vector<Activity> arr = {
        { 'a', 1, 4 },
        { 'b', 3, 5 },
        { 'c', 0, 6 },
        { 'd', 5, 7 },
        { 'e', 3, 8 },
        { 'f', 5, 9 }
    };

    activitySelection(arr);

    return 0;
}
