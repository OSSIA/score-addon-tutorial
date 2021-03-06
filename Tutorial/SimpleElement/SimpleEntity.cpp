#include "SimpleEntity.hpp"

#include <wobjectimpl.h>

W_OBJECT_IMPL(Tutorial::SimpleEntity)
namespace Tutorial
{

SimpleEntity::SimpleEntity(const Id<SimpleEntity>& id, QObject* parent)
    : Entity{id, "SimpleEntity", parent}
{
}

SimpleEntity::~SimpleEntity() {}

}

template <>
void DataStreamReader::read(const Tutorial::SimpleEntity& e)
{
  insertDelimiter();
}

template <>
void DataStreamWriter::write(Tutorial::SimpleEntity& e)
{
  checkDelimiter();
}

template <>
void JSONReader::read(const Tutorial::SimpleEntity& e)
{
}

template <>
void JSONWriter::write(Tutorial::SimpleEntity& e)
{
}
