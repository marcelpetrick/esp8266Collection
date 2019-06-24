#include <cstdlib> // for size_t
#include <string>
#include <vector>

//! @brief Most simple implementation of a size-contrained container for the results (type string).
//!         Offers some convenience-functionality to get the HTML-representation for the web-access.
//!
class ResultContainer
{
public:
    // ctor with size
    ResultContainer(size_t maxSize = 1000);

    // insert
    void insert(std::string input);

    // get HTML-representation
    std::string getHtml();


private:
    // hidden to prevent usage
    ResultContainer() = default;

    // maximum size of the container - just settable via ctor
    size_t _maxSize{0};

    // underlying container
    std::vector<std::string> _container;
};
