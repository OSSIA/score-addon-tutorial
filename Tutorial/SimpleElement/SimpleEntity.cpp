#include "SimpleEntity.hpp"

namespace Tutorial
{

SimpleEntity::SimpleEntity(const Id<SimpleEntity>& id, QObject* parent):
    Entity{id, "SimpleEntity", parent}
{

}

SimpleEntity::~SimpleEntity()
{

}

}

template <>
void DataStreamReader::read(const Tutorial::SimpleEntity& e)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::writeTo(Tutorial::SimpleEntity& e)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(const Tutorial::SimpleEntity& e)
{
}

template <>
void JSONObjectWriter::writeTo(Tutorial::SimpleEntity& e)
{

}
