#if !defined(ForExpression_hpp)
    #define ForExpression_hpp
    #include <AST/Expression.hpp>
    #include <AST/Variable.hpp>
    #include <memory>
namespace kaleidoscope {
    class ForExpression : public Expression {
        std::unique_ptr<Variable> loop_variable;
        std::unique_ptr<Expression> initialize;
        std::unique_ptr<Expression> condition;
        std::unique_ptr<Expression> update;
        std::unique_ptr<Expression> body;

      public:
        ForExpression(std::unique_ptr<Variable> loop_variable,
                      std::unique_ptr<Expression> initialize,
                      std::unique_ptr<Expression> condition,
                      std::unique_ptr<Expression> update,
                      std::unique_ptr<Expression> body);
        const Variable& get_loop_variable() const;
        const std::string& get_loop_variable_name() const;
        const Expression& get_initialize() const;
        const Expression& get_condition() const;
        const Expression& get_update() const;
        const Expression& get_body() const;
        virtual void accept(Visitor& visitor) const override;
    };
}  // namespace kaleidoscope
#endif