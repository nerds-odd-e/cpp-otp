#include <iostream>
#include <fruit/fruit.h>
#include "AuthenticationService.h"

fruit::Component<AuthenticationService> getAuthenticationServiceComponent() {
    return fruit::createComponent();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    fruit::Injector<AuthenticationService> injector(getAuthenticationServiceComponent);
    AuthenticationService authenticationService(injector);
    std::cout << authenticationService.isValid("joey", "91000000") << std::endl;
    return 0;
}

