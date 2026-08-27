class BrowserHistory {
private:
    vector<string> history;
    int current;

public:

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
    }

    void visit(string url) {
        current++;

        if (current < history.size()) {
            history[current] = url;
            history.resize(current + 1);
        }

 else {
            history.push_back(url);
        }
    }

    string back(int steps) {
        current = max(0, current - steps);
        return history[current];
    }

    string forward(int steps) {
        current = min((int)history.size() - 1, current + steps);
        return history[current];
    }
};