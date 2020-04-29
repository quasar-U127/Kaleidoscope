#if !defined(Printer_hpp)
    #define Printer_hpp
    #include <AST/AST.hpp>
    #include <iostream>
    #include <memory>
    #include <vector>
namespace kaleidoscope {
    class Printer : public Visitor {
        std::ostream& cout;
        std::vector<int> header;
        const std::string t, h, e;
        void print_header();

      public:
        Printer(std::ostream& cout);
        virtual void visit(
            const AbstractSyntaxNode& abstract_syntax_node) override;
        virtual void visit(const BinaryExpression& binary_expression) override;
        virtual void visit(const CallExpression& call_expression) override;
        virtual void visit(const Expression& abstract_syntax_node) override;
        virtual void visit(const Function& function) override;
        virtual void visit(const IfElseExpression& function) override;
        virtual void visit(const NumberExpression& number_expression) override;
        virtual void visit(const Prototype& prototype) override;
        virtual void visit(const Variable& variable) override;
    };
}  // namespace kaleidoscope
#endif