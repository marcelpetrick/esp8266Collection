#include <ResultContainer.h>

ResultContainer::ResultContainer(size_t maxSize) :
    _maxSize(maxSize)
{
    // do nothing else
    // todo: maybe check against maxSize, in case the iomplementation says that just certain amount of elements is not supported
}

void ResultContainer::insert(std::string input)
{
    // check size and pop if needed
    // test against the "future" size
    while ((_container.size() + 1) > _maxSize)
    {
        _container.erase(_container.begin());
    }

    // insert the item
    _container.push_back(input);
}

std::string ResultContainer::getHtml()
{
    // todo
    return std::string("not implemented");
}

std::string ResultContainer::getResultString()
{
    std::string result;

    bool notFirstElement{false};
    for(auto const& elem : _container)
    {
        if(notFirstElement)
        {
            result.append(";");
        }
        else
        {
            notFirstElement = true;
        }

        result.append(elem);
    }

    return result;
}
