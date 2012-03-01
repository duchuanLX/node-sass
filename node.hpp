#include <vector>
#include <sstream>
#include "token.hpp"

namespace Sass {
  using std::vector;
  using std::stringstream;
  
  struct Node {
    enum Node_Type {
      null,
      comment,
      ruleset,
      clauses,
      selector_group,
      selector,
      simple_selector_sequence,
      simple_selector,
      rule,
      property,
      values,
      value,
      lookahead_sequence,
      lookahead_token
    };
    
    Node_Type type;
    Token token;
    vector<Node> children;
    vector<Node> opt_children;
    
    Node();
    Node(Node_Type _type);
    Node(Node_Type _type, Token& _token);
    void push_child(const Node& node);
    void push_opt_child(const Node& node);
    void dump(unsigned int depth = 0);
    void emit_nested_css(stringstream& buf, const string& prefix, size_t depth);
    void emit_expanded_css(stringstream& buf, const string& prefix);
  };
}