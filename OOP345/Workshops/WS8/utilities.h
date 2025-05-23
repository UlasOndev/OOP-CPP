#pragma once
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "list.h"
#include "element.h"

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif //!SENECA_UTILITIES_H