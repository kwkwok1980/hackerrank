// https://www.hackerrank.com/challenges/play-game/problem?isFullScreen=true

struct Step {
    int index = 0;
    int count = -1;
    std::uint64_t result = 0;
};

std::vector<Step> steps{};

Step& bricksGameImpl(std::vector<int>& values, int x, int N) {
    Step& step = steps[x];
    if (step.count != -1) {
        //std::cout << x << std::endl;
        return step;
    }
    if (x == N-1) {
        step.count = 1;
        step.result = values[x];
    } else if (x == N-2) {
        step.count = 2;
        step.result = values[x] + values[x+1];
    } else if (x == N-3) {
        step.count = 3;
        step.result = values[x] + values[x+1] + values[x+2];
    } else {
        for (int i=1; i<=3; ++i) {
            std::uint64_t result = 0;
            for (int j=0; j<i; ++j) {
                result = result + values[x+j];
            }
            int nextIndex = x + i;
            if (nextIndex < N) {
                Step& nextStep = bricksGameImpl(values, nextIndex, N);
                int nextNextIndex = nextStep.index + nextStep.count;
                if (nextNextIndex < N) {
                    Step& nextNextStep = bricksGameImpl(values, nextNextIndex, N);
                    result = result + nextNextStep.result;
                }
            }
            if (result > step.result) {
                step.count = i;
                step.result = result;
            }
        }
    }
    return step;
}

std::uint64_t bricksGame(std::vector<int> values) {
    int N = values.size();
    steps = std::vector(N, Step{});
    for (int i=0; i<N; ++i) {
        steps[i].index = i;
        steps[i].count = -1;
        steps[i].result = 0;
    }
    for (int i=N-1; i>=0; --i) {
        bricksGameImpl(values, i, N);
    }
    return steps[0].result;
}
