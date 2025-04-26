vector<int> gradingStudents(vector<int> grades) {
    std::vector<int> results(grades.size(), 0);
    for (int i=0; i< grades.size(); ++i) {
        int grade = grades[i];
        if (grade < 38) {
            results[i] = grade;
        } else {
            int next = ((grade / 5) + 1) * 5;
            if ((next - grade) < 3) {
                results[i] = next;
            } else {
                results[i] = grade;
            }
        }
    }
    return results;
}
