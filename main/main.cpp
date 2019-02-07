#include <iostream>
#include <fruit/fruit.h>
#include "AuthenticationService.h"

fruit::Component<IAuthenticationService> getAuthenticationServiceComponent() {
    return fruit::createComponent()
            .bind<IRsaTokenDao, RsaTokenDao>()
            .bind<ILogger, Logger>()
            .bind<IProfileDao, ProfileDao>()
            .bind<IAuthenticationService, AuthenticationService>();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    fruit::Injector<IAuthenticationService> injector(getAuthenticationServiceComponent);
    IAuthenticationService *authenticationService = injector.get<IAuthenticationService *>();
    std::cout << authenticationService->isValid("joey", "91000000") << std::endl;
    return 0;
}

