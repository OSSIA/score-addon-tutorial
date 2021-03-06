#include "ConcretePolymorphicEntity.hpp"

#include <wobjectimpl.h>

W_OBJECT_IMPL(Tutorial::ConcretePolymorphicEntity)
namespace Tutorial
{

ConcretePolymorphicEntity::ConcretePolymorphicEntity(
    const Id<PolymorphicEntity>& id,
    QObject* parent)
    : PolymorphicEntity{id, parent}
{
}

int ConcretePolymorphicEntity::someVirtualMethod() const
{
  return 1234;
}

}

// Here we do not need to save the parent class.
// This is because the serialization mechanism will
// be called from the point of view of the PolymorphicElement class.
template <>
void DataStreamReader::read(const Tutorial::ConcretePolymorphicEntity& p)
{
  insertDelimiter();
}

template <>
void DataStreamWriter::write(Tutorial::ConcretePolymorphicEntity& p)
{
  checkDelimiter();
}

template <>
void JSONReader::read(const Tutorial::ConcretePolymorphicEntity& p)
{
}

template <>
void JSONWriter::write(Tutorial::ConcretePolymorphicEntity& p)
{
}
