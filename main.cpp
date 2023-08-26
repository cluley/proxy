#include "proxy.h"

int main() {
    auto real_db = VeryHeavyDatabase();
    auto cached_db = CacheProxyDB(real_db);
    auto test_db = TestDB(real_db);
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << test_db.GetData("key") << std::endl;

    auto limit_db = OneShotDB(real_db, 2);
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;

    return 0;
}