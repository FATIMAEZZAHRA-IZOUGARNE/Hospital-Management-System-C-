#pragma once
#include <iostream>


namespace Hospital {
    class Insurance;

    class Payment {
    private:
        std::string method;       // Méthode de paiement : Cash, CreditCard, Paypal
        double amount;   
        Insurance* insurance;   // Assurance optionnelle

    public:
        // ===== Constructor =====
        Payment(const std::string& m = "Cash", double a = 0.0, Insurance* ins = nullptr);
         // ===== Destructor =====
        ~Payment(){}

        // ===== Methods =====
        double computeFinalAmount() const;
        void pay() const;
        void display() const;

        // ===== Getters =====
        double getAmount() const;
        const std::string& getMethod() const;
       

        // ===== Setters =====
        void setMethod(const std::string& m);
       
    };

}
