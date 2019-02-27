#include <iostream>
#include <fruit/fruit.h>
#include "AuthenticationService.h"
#include "NowString.h"

fruit::Component<AuthenticationService> getAuthenticationServiceComponent() {
    return fruit::createComponent();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    fruit::Injector<AuthenticationService> injector(getAuthenticationServiceComponent);
    AuthenticationService authenticationService(injector);
    bool isValid = authenticationService.isValid("joey", "91000000");
    std::cout << "IsValid: " << std::boolalpha << isValid << std::endl;

    auto factory = std::make_shared<NowStringFactory>();
    auto now = factory->createNowString();
    std::cout << now.get() << std::endl;

    return 0;
}

