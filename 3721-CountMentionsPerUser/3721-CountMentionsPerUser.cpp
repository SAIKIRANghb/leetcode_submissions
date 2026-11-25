// Last updated: 11/25/2026, 3:37:58 PM
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // Sort events by timestamp
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timestampA = stoll(a[1]);
            int timestampB = stoll(b[1]);
            
            if (timestampA == timestampB) {
                // If timestamps are the same, compare event type: OFFLINE comes before MESSAGE
                return a[0] == "OFFLINE" && b[0] == "MESSAGE";
            }
            return timestampA < timestampB;
        });

        unordered_map<int, int> offline; // Map to track offline users and their re-online time
        vector<int> mentions(numberOfUsers, 0); // Result vector for mentions

        for (const auto& event : events) {
            string eventType = event[0];
            int timestamp = stoll(event[1]); // Convert timestamp to integer

            // Process expired offline users before handling the current event
            vector<int> toErase;
            for (auto& [id, onlineTime] : offline) {
                if (onlineTime <= timestamp) {
                    toErase.push_back(id); // Mark users who are now back online
                }
            }
            for (int id : toErase) {
                offline.erase(id);
            }

            // Handle "OFFLINE" events
            if (eventType == "OFFLINE") {
                int userId = stoi(event[2]);
                offline[userId] = timestamp + 60; // User goes offline for 60 units of time
            }

            // Handle "MESSAGE" events
            else if (eventType == "MESSAGE") {
                string mentionsString = event[2];

                // Process mentions
                if (mentionsString == "ALL") {
                    // Mention all users (including offline users)
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (mentionsString == "HERE") {
                    // Mention only online users
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offline.find(i) == offline.end()) { // User is online
                            mentions[i]++;
                        }
                    }
                } else {
                    // Parse specific user IDs (e.g., "id0 id1 id2")
                    stringstream ss(mentionsString);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2)); // Extract user ID
                            mentions[userId]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};
