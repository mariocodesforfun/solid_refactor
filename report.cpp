#include <iostream>
#include <sstream>
#include <string>

class DataProcessor {
public:
    virtual int process(const std::string& data) = 0;
    virtual ~DataProcessor() = default;
};

class SumProcessor : public DataProcessor {
public:
    int process(const std::string& data) override {
        std::istringstream in(data);
        int x, sum = 0;
        while (in >> x) sum += x;
        return sum;
    }
};

class Formatter {
public:
    virtual std::string format(const std::string& title, int result) = 0;
    virtual ~Formatter() = default;
};

class HtmlFormatter : public Formatter {
public:
    std::string format(const std::string& title, int result) override {
        return "<h1>" + title + "</h1>\n<p>Total: " + std::to_string(result) + "</p>";
    }
};

class TextFormatter : public Formatter {
public:
    std::string format(const std::string& title, int result) override {
        return title + "\nTotal: " + std::to_string(result);
    }
};

class Report {
    std::string title, data;
    DataProcessor& processor;
    Formatter& formatter;
public:
    Report(const std::string& t, const std::string& d, DataProcessor& p, Formatter& f)
        : title(t), data(d), processor(p), formatter(f) {}

    std::string generate() {
        int result = processor.process(data);
        return formatter.format(title, result);
    }
};

int main() {
    SumProcessor sumProc;
    HtmlFormatter html;
    TextFormatter text;

    Report r1("Sales", "51 42 39 60", sumProc, html);
    std::cout << r1.generate() << "\n\n";

    Report r2("Sales", "51 42 39 60", sumProc, text);
    std::cout << r2.generate() << std::endl;
}
