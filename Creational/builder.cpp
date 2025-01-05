#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace  std;

// Scenario: building a component that render web pages.

struct HTMLBuilder;
struct HTMLElement
{
    string name;
    string text;
    vector<HTMLElement> elements;
    const size_t indent_size = 2;

    HTMLElement() = default;
    HTMLElement(const string& name, const string& text)
        : name(name), text(text) {}

    friend ostream& operator<<(ostream& os, const HTMLElement& e)
    {
        return os << e.str();
    }

    [[nodiscard]] string str(int indent = 0) const
    {
        ostringstream oss;
        const string i(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (!text.empty())
            oss << string(indent_size*(indent+1), ' ') << text << endl;

        for (const auto& elem : elements)
            oss << elem.str(indent + 1) << endl;
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }

    static unique_ptr<HTMLBuilder> build(const string& root_name)
    {
        return make_unique<HTMLBuilder>(root_name);
    }
};

struct HTMLBuilder
{
    HTMLElement root;

    explicit HTMLBuilder(const string& root_name)
    {
        root.name = root_name;
    }

    HTMLBuilder& add_child(const string& child_name, const string& child_text)
    {
        HTMLElement e(child_name, child_text);
        root.elements.emplace_back(e);
        return *this;
    }

    HTMLBuilder* add_child2(const string& child_name, const string& child_text)
    {
        HTMLElement e(child_name, child_text);
        root.elements.emplace_back(e);
        return this;
    }

    friend ostream& operator<<(ostream& os, const HTMLBuilder& e)
    {
        return os << e.str();
    }

    [[nodiscard]] string str() const
    {
        return root.str();
    }
};

int main()
{
    HTMLBuilder builder{ "ul" };
    builder.add_child("li", "xin")
        .add_child("chao", "world");

    cout << builder << endl;

    auto builder2 = HTMLElement::build("ul");
    builder2->add_child2("li", "hello")
            ->add_child2("li", "world");
    cout << (*builder2) << endl;

    return 0;
}