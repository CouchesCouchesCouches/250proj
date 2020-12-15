//
// Generated file, do not edit! Created by nedtool 5.6 from classical_messages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "classical_messages_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace quisp {
namespace messages {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(deleteThisModule)

deleteThisModule::deleteThisModule(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
}

deleteThisModule::deleteThisModule(const deleteThisModule& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

deleteThisModule::~deleteThisModule()
{
}

deleteThisModule& deleteThisModule::operator=(const deleteThisModule& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void deleteThisModule::copy(const deleteThisModule& other)
{
}

void deleteThisModule::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
}

void deleteThisModule::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
}

class deleteThisModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    deleteThisModuleDescriptor();
    virtual ~deleteThisModuleDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(deleteThisModuleDescriptor)

deleteThisModuleDescriptor::deleteThisModuleDescriptor() : omnetpp::cClassDescriptor("quisp::messages::deleteThisModule", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

deleteThisModuleDescriptor::~deleteThisModuleDescriptor()
{
    delete[] propertynames;
}

bool deleteThisModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<deleteThisModule *>(obj)!=nullptr;
}

const char **deleteThisModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *deleteThisModuleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int deleteThisModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int deleteThisModuleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *deleteThisModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int deleteThisModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *deleteThisModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **deleteThisModuleDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *deleteThisModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int deleteThisModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    deleteThisModule *pp = (deleteThisModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *deleteThisModuleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    deleteThisModule *pp = (deleteThisModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string deleteThisModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    deleteThisModule *pp = (deleteThisModule *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool deleteThisModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    deleteThisModule *pp = (deleteThisModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *deleteThisModuleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *deleteThisModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    deleteThisModule *pp = (deleteThisModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(header)

header::header(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->srcAddr = 0;
    this->destAddr = 0;
    this->hopCount = 0;
}

header::header(const header& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

header::~header()
{
}

header& header::operator=(const header& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void header::copy(const header& other)
{
    this->srcAddr = other.srcAddr;
    this->destAddr = other.destAddr;
    this->hopCount = other.hopCount;
}

void header::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->hopCount);
}

void header::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->hopCount);
}

int header::getSrcAddr() const
{
    return this->srcAddr;
}

void header::setSrcAddr(int srcAddr)
{
    this->srcAddr = srcAddr;
}

int header::getDestAddr() const
{
    return this->destAddr;
}

void header::setDestAddr(int destAddr)
{
    this->destAddr = destAddr;
}

int header::getHopCount() const
{
    return this->hopCount;
}

void header::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

class headerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    headerDescriptor();
    virtual ~headerDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(headerDescriptor)

headerDescriptor::headerDescriptor() : omnetpp::cClassDescriptor("quisp::messages::header", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

headerDescriptor::~headerDescriptor()
{
    delete[] propertynames;
}

bool headerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<header *>(obj)!=nullptr;
}

const char **headerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *headerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int headerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int headerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *headerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "destAddr",
        "hopCount",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int headerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *headerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **headerDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *headerDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int headerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    header *pp = (header *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *headerDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    header *pp = (header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string headerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    header *pp = (header *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcAddr());
        case 1: return long2string(pp->getDestAddr());
        case 2: return long2string(pp->getHopCount());
        default: return "";
    }
}

bool headerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    header *pp = (header *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcAddr(string2long(value)); return true;
        case 1: pp->setDestAddr(string2long(value)); return true;
        case 2: pp->setHopCount(string2long(value)); return true;
        default: return false;
    }
}

const char *headerDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *headerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    header *pp = (header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ConnectionSetupRequest)

ConnectionSetupRequest::ConnectionSetupRequest(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->actual_destAddr = 0;
    this->actual_srcAddr = 0;
    this->num_measure = 0;
    this->number_of_required_Bellpairs = 0;
    this->required_fidelity = 0;
    stack_of_QNodeIndexes_arraysize = 0;
    this->stack_of_QNodeIndexes = 0;
    stack_of_linkCosts_arraysize = 0;
    this->stack_of_linkCosts = 0;
    stack_of_QNICs_arraysize = 0;
    this->stack_of_QNICs = 0;
}

ConnectionSetupRequest::ConnectionSetupRequest(const ConnectionSetupRequest& other) : ::quisp::messages::header(other)
{
    stack_of_QNodeIndexes_arraysize = 0;
    this->stack_of_QNodeIndexes = 0;
    stack_of_linkCosts_arraysize = 0;
    this->stack_of_linkCosts = 0;
    stack_of_QNICs_arraysize = 0;
    this->stack_of_QNICs = 0;
    copy(other);
}

ConnectionSetupRequest::~ConnectionSetupRequest()
{
    delete [] this->stack_of_QNodeIndexes;
    delete [] this->stack_of_linkCosts;
    delete [] this->stack_of_QNICs;
}

ConnectionSetupRequest& ConnectionSetupRequest::operator=(const ConnectionSetupRequest& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void ConnectionSetupRequest::copy(const ConnectionSetupRequest& other)
{
    this->actual_destAddr = other.actual_destAddr;
    this->actual_srcAddr = other.actual_srcAddr;
    this->num_measure = other.num_measure;
    this->number_of_required_Bellpairs = other.number_of_required_Bellpairs;
    this->required_fidelity = other.required_fidelity;
    delete [] this->stack_of_QNodeIndexes;
    this->stack_of_QNodeIndexes = (other.stack_of_QNodeIndexes_arraysize==0) ? nullptr : new int[other.stack_of_QNodeIndexes_arraysize];
    stack_of_QNodeIndexes_arraysize = other.stack_of_QNodeIndexes_arraysize;
    for (unsigned int i=0; i<stack_of_QNodeIndexes_arraysize; i++)
        this->stack_of_QNodeIndexes[i] = other.stack_of_QNodeIndexes[i];
    delete [] this->stack_of_linkCosts;
    this->stack_of_linkCosts = (other.stack_of_linkCosts_arraysize==0) ? nullptr : new int[other.stack_of_linkCosts_arraysize];
    stack_of_linkCosts_arraysize = other.stack_of_linkCosts_arraysize;
    for (unsigned int i=0; i<stack_of_linkCosts_arraysize; i++)
        this->stack_of_linkCosts[i] = other.stack_of_linkCosts[i];
    delete [] this->stack_of_QNICs;
    this->stack_of_QNICs = (other.stack_of_QNICs_arraysize==0) ? nullptr : new QNIC_pair_info[other.stack_of_QNICs_arraysize];
    stack_of_QNICs_arraysize = other.stack_of_QNICs_arraysize;
    for (unsigned int i=0; i<stack_of_QNICs_arraysize; i++)
        this->stack_of_QNICs[i] = other.stack_of_QNICs[i];
}

void ConnectionSetupRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->actual_destAddr);
    doParsimPacking(b,this->actual_srcAddr);
    doParsimPacking(b,this->num_measure);
    doParsimPacking(b,this->number_of_required_Bellpairs);
    doParsimPacking(b,this->required_fidelity);
    b->pack(stack_of_QNodeIndexes_arraysize);
    doParsimArrayPacking(b,this->stack_of_QNodeIndexes,stack_of_QNodeIndexes_arraysize);
    b->pack(stack_of_linkCosts_arraysize);
    doParsimArrayPacking(b,this->stack_of_linkCosts,stack_of_linkCosts_arraysize);
    b->pack(stack_of_QNICs_arraysize);
    doParsimArrayPacking(b,this->stack_of_QNICs,stack_of_QNICs_arraysize);
}

void ConnectionSetupRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->actual_destAddr);
    doParsimUnpacking(b,this->actual_srcAddr);
    doParsimUnpacking(b,this->num_measure);
    doParsimUnpacking(b,this->number_of_required_Bellpairs);
    doParsimUnpacking(b,this->required_fidelity);
    delete [] this->stack_of_QNodeIndexes;
    b->unpack(stack_of_QNodeIndexes_arraysize);
    if (stack_of_QNodeIndexes_arraysize==0) {
        this->stack_of_QNodeIndexes = 0;
    } else {
        this->stack_of_QNodeIndexes = new int[stack_of_QNodeIndexes_arraysize];
        doParsimArrayUnpacking(b,this->stack_of_QNodeIndexes,stack_of_QNodeIndexes_arraysize);
    }
    delete [] this->stack_of_linkCosts;
    b->unpack(stack_of_linkCosts_arraysize);
    if (stack_of_linkCosts_arraysize==0) {
        this->stack_of_linkCosts = 0;
    } else {
        this->stack_of_linkCosts = new int[stack_of_linkCosts_arraysize];
        doParsimArrayUnpacking(b,this->stack_of_linkCosts,stack_of_linkCosts_arraysize);
    }
    delete [] this->stack_of_QNICs;
    b->unpack(stack_of_QNICs_arraysize);
    if (stack_of_QNICs_arraysize==0) {
        this->stack_of_QNICs = 0;
    } else {
        this->stack_of_QNICs = new QNIC_pair_info[stack_of_QNICs_arraysize];
        doParsimArrayUnpacking(b,this->stack_of_QNICs,stack_of_QNICs_arraysize);
    }
}

int ConnectionSetupRequest::getActual_destAddr() const
{
    return this->actual_destAddr;
}

void ConnectionSetupRequest::setActual_destAddr(int actual_destAddr)
{
    this->actual_destAddr = actual_destAddr;
}

int ConnectionSetupRequest::getActual_srcAddr() const
{
    return this->actual_srcAddr;
}

void ConnectionSetupRequest::setActual_srcAddr(int actual_srcAddr)
{
    this->actual_srcAddr = actual_srcAddr;
}

int ConnectionSetupRequest::getNum_measure() const
{
    return this->num_measure;
}

void ConnectionSetupRequest::setNum_measure(int num_measure)
{
    this->num_measure = num_measure;
}

int ConnectionSetupRequest::getNumber_of_required_Bellpairs() const
{
    return this->number_of_required_Bellpairs;
}

void ConnectionSetupRequest::setNumber_of_required_Bellpairs(int number_of_required_Bellpairs)
{
    this->number_of_required_Bellpairs = number_of_required_Bellpairs;
}

double ConnectionSetupRequest::getRequired_fidelity() const
{
    return this->required_fidelity;
}

void ConnectionSetupRequest::setRequired_fidelity(double required_fidelity)
{
    this->required_fidelity = required_fidelity;
}

void ConnectionSetupRequest::setStack_of_QNodeIndexesArraySize(unsigned int size)
{
    int *stack_of_QNodeIndexes2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = stack_of_QNodeIndexes_arraysize < size ? stack_of_QNodeIndexes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        stack_of_QNodeIndexes2[i] = this->stack_of_QNodeIndexes[i];
    for (unsigned int i=sz; i<size; i++)
        stack_of_QNodeIndexes2[i] = 0;
    stack_of_QNodeIndexes_arraysize = size;
    delete [] this->stack_of_QNodeIndexes;
    this->stack_of_QNodeIndexes = stack_of_QNodeIndexes2;
}

unsigned int ConnectionSetupRequest::getStack_of_QNodeIndexesArraySize() const
{
    return stack_of_QNodeIndexes_arraysize;
}

int ConnectionSetupRequest::getStack_of_QNodeIndexes(unsigned int k) const
{
    if (k>=stack_of_QNodeIndexes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_QNodeIndexes_arraysize, k);
    return this->stack_of_QNodeIndexes[k];
}

void ConnectionSetupRequest::setStack_of_QNodeIndexes(unsigned int k, int stack_of_QNodeIndexes)
{
    if (k>=stack_of_QNodeIndexes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_QNodeIndexes_arraysize, k);
    this->stack_of_QNodeIndexes[k] = stack_of_QNodeIndexes;
}

void ConnectionSetupRequest::setStack_of_linkCostsArraySize(unsigned int size)
{
    int *stack_of_linkCosts2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = stack_of_linkCosts_arraysize < size ? stack_of_linkCosts_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        stack_of_linkCosts2[i] = this->stack_of_linkCosts[i];
    for (unsigned int i=sz; i<size; i++)
        stack_of_linkCosts2[i] = 0;
    stack_of_linkCosts_arraysize = size;
    delete [] this->stack_of_linkCosts;
    this->stack_of_linkCosts = stack_of_linkCosts2;
}

unsigned int ConnectionSetupRequest::getStack_of_linkCostsArraySize() const
{
    return stack_of_linkCosts_arraysize;
}

int ConnectionSetupRequest::getStack_of_linkCosts(unsigned int k) const
{
    if (k>=stack_of_linkCosts_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_linkCosts_arraysize, k);
    return this->stack_of_linkCosts[k];
}

void ConnectionSetupRequest::setStack_of_linkCosts(unsigned int k, int stack_of_linkCosts)
{
    if (k>=stack_of_linkCosts_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_linkCosts_arraysize, k);
    this->stack_of_linkCosts[k] = stack_of_linkCosts;
}

void ConnectionSetupRequest::setStack_of_QNICsArraySize(unsigned int size)
{
    QNIC_pair_info *stack_of_QNICs2 = (size==0) ? nullptr : new QNIC_pair_info[size];
    unsigned int sz = stack_of_QNICs_arraysize < size ? stack_of_QNICs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        stack_of_QNICs2[i] = this->stack_of_QNICs[i];
    stack_of_QNICs_arraysize = size;
    delete [] this->stack_of_QNICs;
    this->stack_of_QNICs = stack_of_QNICs2;
}

unsigned int ConnectionSetupRequest::getStack_of_QNICsArraySize() const
{
    return stack_of_QNICs_arraysize;
}

QNIC_pair_info& ConnectionSetupRequest::getStack_of_QNICs(unsigned int k)
{
    if (k>=stack_of_QNICs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_QNICs_arraysize, k);
    return this->stack_of_QNICs[k];
}

void ConnectionSetupRequest::setStack_of_QNICs(unsigned int k, const QNIC_pair_info& stack_of_QNICs)
{
    if (k>=stack_of_QNICs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_QNICs_arraysize, k);
    this->stack_of_QNICs[k] = stack_of_QNICs;
}

class ConnectionSetupRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ConnectionSetupRequestDescriptor();
    virtual ~ConnectionSetupRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ConnectionSetupRequestDescriptor)

ConnectionSetupRequestDescriptor::ConnectionSetupRequestDescriptor() : omnetpp::cClassDescriptor("quisp::messages::ConnectionSetupRequest", "quisp::messages::header")
{
    propertynames = nullptr;
}

ConnectionSetupRequestDescriptor::~ConnectionSetupRequestDescriptor()
{
    delete[] propertynames;
}

bool ConnectionSetupRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ConnectionSetupRequest *>(obj)!=nullptr;
}

const char **ConnectionSetupRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ConnectionSetupRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ConnectionSetupRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int ConnectionSetupRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *ConnectionSetupRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "actual_destAddr",
        "actual_srcAddr",
        "num_measure",
        "number_of_required_Bellpairs",
        "required_fidelity",
        "stack_of_QNodeIndexes",
        "stack_of_linkCosts",
        "stack_of_QNICs",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int ConnectionSetupRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "actual_destAddr")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "actual_srcAddr")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "num_measure")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "number_of_required_Bellpairs")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "required_fidelity")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "stack_of_QNodeIndexes")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "stack_of_linkCosts")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "stack_of_QNICs")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ConnectionSetupRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "double",
        "int",
        "int",
        "QNIC_pair_info",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **ConnectionSetupRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ConnectionSetupRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ConnectionSetupRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupRequest *pp = (ConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        case 5: return pp->getStack_of_QNodeIndexesArraySize();
        case 6: return pp->getStack_of_linkCostsArraySize();
        case 7: return pp->getStack_of_QNICsArraySize();
        default: return 0;
    }
}

const char *ConnectionSetupRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupRequest *pp = (ConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ConnectionSetupRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupRequest *pp = (ConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getActual_destAddr());
        case 1: return long2string(pp->getActual_srcAddr());
        case 2: return long2string(pp->getNum_measure());
        case 3: return long2string(pp->getNumber_of_required_Bellpairs());
        case 4: return double2string(pp->getRequired_fidelity());
        case 5: return long2string(pp->getStack_of_QNodeIndexes(i));
        case 6: return long2string(pp->getStack_of_linkCosts(i));
        case 7: {std::stringstream out; out << pp->getStack_of_QNICs(i); return out.str();}
        default: return "";
    }
}

bool ConnectionSetupRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupRequest *pp = (ConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setActual_destAddr(string2long(value)); return true;
        case 1: pp->setActual_srcAddr(string2long(value)); return true;
        case 2: pp->setNum_measure(string2long(value)); return true;
        case 3: pp->setNumber_of_required_Bellpairs(string2long(value)); return true;
        case 4: pp->setRequired_fidelity(string2double(value)); return true;
        case 5: pp->setStack_of_QNodeIndexes(i,string2long(value)); return true;
        case 6: pp->setStack_of_linkCosts(i,string2long(value)); return true;
        default: return false;
    }
}

const char *ConnectionSetupRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(QNIC_pair_info));
        default: return nullptr;
    };
}

void *ConnectionSetupRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupRequest *pp = (ConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getStack_of_QNICs(i)); break;
        default: return nullptr;
    }
}

Register_Class(RejectConnectionSetupRequest)

RejectConnectionSetupRequest::RejectConnectionSetupRequest(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->actual_destAddr = 0;
    this->actual_srcAddr = 0;
    this->number_of_required_Bellpairs = 0;
}

RejectConnectionSetupRequest::RejectConnectionSetupRequest(const RejectConnectionSetupRequest& other) : ::quisp::messages::header(other)
{
    copy(other);
}

RejectConnectionSetupRequest::~RejectConnectionSetupRequest()
{
}

RejectConnectionSetupRequest& RejectConnectionSetupRequest::operator=(const RejectConnectionSetupRequest& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void RejectConnectionSetupRequest::copy(const RejectConnectionSetupRequest& other)
{
    this->actual_destAddr = other.actual_destAddr;
    this->actual_srcAddr = other.actual_srcAddr;
    this->number_of_required_Bellpairs = other.number_of_required_Bellpairs;
}

void RejectConnectionSetupRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->actual_destAddr);
    doParsimPacking(b,this->actual_srcAddr);
    doParsimPacking(b,this->number_of_required_Bellpairs);
}

void RejectConnectionSetupRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->actual_destAddr);
    doParsimUnpacking(b,this->actual_srcAddr);
    doParsimUnpacking(b,this->number_of_required_Bellpairs);
}

int RejectConnectionSetupRequest::getActual_destAddr() const
{
    return this->actual_destAddr;
}

void RejectConnectionSetupRequest::setActual_destAddr(int actual_destAddr)
{
    this->actual_destAddr = actual_destAddr;
}

int RejectConnectionSetupRequest::getActual_srcAddr() const
{
    return this->actual_srcAddr;
}

void RejectConnectionSetupRequest::setActual_srcAddr(int actual_srcAddr)
{
    this->actual_srcAddr = actual_srcAddr;
}

int RejectConnectionSetupRequest::getNumber_of_required_Bellpairs() const
{
    return this->number_of_required_Bellpairs;
}

void RejectConnectionSetupRequest::setNumber_of_required_Bellpairs(int number_of_required_Bellpairs)
{
    this->number_of_required_Bellpairs = number_of_required_Bellpairs;
}

class RejectConnectionSetupRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RejectConnectionSetupRequestDescriptor();
    virtual ~RejectConnectionSetupRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(RejectConnectionSetupRequestDescriptor)

RejectConnectionSetupRequestDescriptor::RejectConnectionSetupRequestDescriptor() : omnetpp::cClassDescriptor("quisp::messages::RejectConnectionSetupRequest", "quisp::messages::header")
{
    propertynames = nullptr;
}

RejectConnectionSetupRequestDescriptor::~RejectConnectionSetupRequestDescriptor()
{
    delete[] propertynames;
}

bool RejectConnectionSetupRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RejectConnectionSetupRequest *>(obj)!=nullptr;
}

const char **RejectConnectionSetupRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RejectConnectionSetupRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RejectConnectionSetupRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RejectConnectionSetupRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RejectConnectionSetupRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "actual_destAddr",
        "actual_srcAddr",
        "number_of_required_Bellpairs",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int RejectConnectionSetupRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "actual_destAddr")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "actual_srcAddr")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "number_of_required_Bellpairs")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RejectConnectionSetupRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **RejectConnectionSetupRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RejectConnectionSetupRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RejectConnectionSetupRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RejectConnectionSetupRequest *pp = (RejectConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RejectConnectionSetupRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RejectConnectionSetupRequest *pp = (RejectConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RejectConnectionSetupRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RejectConnectionSetupRequest *pp = (RejectConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getActual_destAddr());
        case 1: return long2string(pp->getActual_srcAddr());
        case 2: return long2string(pp->getNumber_of_required_Bellpairs());
        default: return "";
    }
}

bool RejectConnectionSetupRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RejectConnectionSetupRequest *pp = (RejectConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setActual_destAddr(string2long(value)); return true;
        case 1: pp->setActual_srcAddr(string2long(value)); return true;
        case 2: pp->setNumber_of_required_Bellpairs(string2long(value)); return true;
        default: return false;
    }
}

const char *RejectConnectionSetupRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *RejectConnectionSetupRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RejectConnectionSetupRequest *pp = (RejectConnectionSetupRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LinkTomographyRuleSet)

LinkTomographyRuleSet::LinkTomographyRuleSet(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->process_id = 0;
    this->number_of_measuring_resources = 0;
}

LinkTomographyRuleSet::LinkTomographyRuleSet(const LinkTomographyRuleSet& other) : ::quisp::messages::header(other)
{
    copy(other);
}

LinkTomographyRuleSet::~LinkTomographyRuleSet()
{
}

LinkTomographyRuleSet& LinkTomographyRuleSet::operator=(const LinkTomographyRuleSet& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void LinkTomographyRuleSet::copy(const LinkTomographyRuleSet& other)
{
    this->process_id = other.process_id;
    this->number_of_measuring_resources = other.number_of_measuring_resources;
    this->RuleSet = other.RuleSet;
}

void LinkTomographyRuleSet::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->process_id);
    doParsimPacking(b,this->number_of_measuring_resources);
    doParsimPacking(b,this->RuleSet);
}

void LinkTomographyRuleSet::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->process_id);
    doParsimUnpacking(b,this->number_of_measuring_resources);
    doParsimUnpacking(b,this->RuleSet);
}

int LinkTomographyRuleSet::getProcess_id() const
{
    return this->process_id;
}

void LinkTomographyRuleSet::setProcess_id(int process_id)
{
    this->process_id = process_id;
}

int LinkTomographyRuleSet::getNumber_of_measuring_resources() const
{
    return this->number_of_measuring_resources;
}

void LinkTomographyRuleSet::setNumber_of_measuring_resources(int number_of_measuring_resources)
{
    this->number_of_measuring_resources = number_of_measuring_resources;
}

RuleSetField& LinkTomographyRuleSet::getRuleSet()
{
    return this->RuleSet;
}

void LinkTomographyRuleSet::setRuleSet(const RuleSetField& RuleSet)
{
    this->RuleSet = RuleSet;
}

class LinkTomographyRuleSetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LinkTomographyRuleSetDescriptor();
    virtual ~LinkTomographyRuleSetDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LinkTomographyRuleSetDescriptor)

LinkTomographyRuleSetDescriptor::LinkTomographyRuleSetDescriptor() : omnetpp::cClassDescriptor("quisp::messages::LinkTomographyRuleSet", "quisp::messages::header")
{
    propertynames = nullptr;
}

LinkTomographyRuleSetDescriptor::~LinkTomographyRuleSetDescriptor()
{
    delete[] propertynames;
}

bool LinkTomographyRuleSetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LinkTomographyRuleSet *>(obj)!=nullptr;
}

const char **LinkTomographyRuleSetDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkTomographyRuleSetDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkTomographyRuleSetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LinkTomographyRuleSetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *LinkTomographyRuleSetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "process_id",
        "number_of_measuring_resources",
        "RuleSet",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int LinkTomographyRuleSetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "process_id")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "number_of_measuring_resources")==0) return base+1;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkTomographyRuleSetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "RuleSetField",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **LinkTomographyRuleSetDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LinkTomographyRuleSetDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LinkTomographyRuleSetDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRuleSet *pp = (LinkTomographyRuleSet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LinkTomographyRuleSetDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRuleSet *pp = (LinkTomographyRuleSet *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkTomographyRuleSetDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRuleSet *pp = (LinkTomographyRuleSet *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getProcess_id());
        case 1: return long2string(pp->getNumber_of_measuring_resources());
        case 2: {std::stringstream out; out << pp->getRuleSet(); return out.str();}
        default: return "";
    }
}

bool LinkTomographyRuleSetDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRuleSet *pp = (LinkTomographyRuleSet *)object; (void)pp;
    switch (field) {
        case 0: pp->setProcess_id(string2long(value)); return true;
        case 1: pp->setNumber_of_measuring_resources(string2long(value)); return true;
        default: return false;
    }
}

const char *LinkTomographyRuleSetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(RuleSetField));
        default: return nullptr;
    };
}

void *LinkTomographyRuleSetDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRuleSet *pp = (LinkTomographyRuleSet *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getRuleSet()); break;
        default: return nullptr;
    }
}

Register_Class(LinkTomographyRequest)

LinkTomographyRequest::LinkTomographyRequest(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
}

LinkTomographyRequest::LinkTomographyRequest(const LinkTomographyRequest& other) : ::quisp::messages::header(other)
{
    copy(other);
}

LinkTomographyRequest::~LinkTomographyRequest()
{
}

LinkTomographyRequest& LinkTomographyRequest::operator=(const LinkTomographyRequest& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void LinkTomographyRequest::copy(const LinkTomographyRequest& other)
{
}

void LinkTomographyRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
}

void LinkTomographyRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
}

class LinkTomographyRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LinkTomographyRequestDescriptor();
    virtual ~LinkTomographyRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LinkTomographyRequestDescriptor)

LinkTomographyRequestDescriptor::LinkTomographyRequestDescriptor() : omnetpp::cClassDescriptor("quisp::messages::LinkTomographyRequest", "quisp::messages::header")
{
    propertynames = nullptr;
}

LinkTomographyRequestDescriptor::~LinkTomographyRequestDescriptor()
{
    delete[] propertynames;
}

bool LinkTomographyRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LinkTomographyRequest *>(obj)!=nullptr;
}

const char **LinkTomographyRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkTomographyRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkTomographyRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int LinkTomographyRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *LinkTomographyRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int LinkTomographyRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkTomographyRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **LinkTomographyRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LinkTomographyRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LinkTomographyRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRequest *pp = (LinkTomographyRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LinkTomographyRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRequest *pp = (LinkTomographyRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkTomographyRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRequest *pp = (LinkTomographyRequest *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool LinkTomographyRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRequest *pp = (LinkTomographyRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *LinkTomographyRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *LinkTomographyRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyRequest *pp = (LinkTomographyRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LinkTomographyAck)

LinkTomographyAck::LinkTomographyAck(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->qnic_index = 0;
}

LinkTomographyAck::LinkTomographyAck(const LinkTomographyAck& other) : ::quisp::messages::header(other)
{
    copy(other);
}

LinkTomographyAck::~LinkTomographyAck()
{
}

LinkTomographyAck& LinkTomographyAck::operator=(const LinkTomographyAck& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void LinkTomographyAck::copy(const LinkTomographyAck& other)
{
    this->qnic_type = other.qnic_type;
    this->qnic_index = other.qnic_index;
}

void LinkTomographyAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->qnic_type);
    doParsimPacking(b,this->qnic_index);
}

void LinkTomographyAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->qnic_type);
    doParsimUnpacking(b,this->qnic_index);
}

QNIC_type& LinkTomographyAck::getQnic_type()
{
    return this->qnic_type;
}

void LinkTomographyAck::setQnic_type(const QNIC_type& qnic_type)
{
    this->qnic_type = qnic_type;
}

int LinkTomographyAck::getQnic_index() const
{
    return this->qnic_index;
}

void LinkTomographyAck::setQnic_index(int qnic_index)
{
    this->qnic_index = qnic_index;
}

class LinkTomographyAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LinkTomographyAckDescriptor();
    virtual ~LinkTomographyAckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LinkTomographyAckDescriptor)

LinkTomographyAckDescriptor::LinkTomographyAckDescriptor() : omnetpp::cClassDescriptor("quisp::messages::LinkTomographyAck", "quisp::messages::header")
{
    propertynames = nullptr;
}

LinkTomographyAckDescriptor::~LinkTomographyAckDescriptor()
{
    delete[] propertynames;
}

bool LinkTomographyAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LinkTomographyAck *>(obj)!=nullptr;
}

const char **LinkTomographyAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkTomographyAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkTomographyAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LinkTomographyAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *LinkTomographyAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "qnic_type",
        "qnic_index",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int LinkTomographyAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_type")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_index")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkTomographyAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "QNIC_type",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **LinkTomographyAckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LinkTomographyAckDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LinkTomographyAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyAck *pp = (LinkTomographyAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LinkTomographyAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyAck *pp = (LinkTomographyAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkTomographyAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyAck *pp = (LinkTomographyAck *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getQnic_type(); return out.str();}
        case 1: return long2string(pp->getQnic_index());
        default: return "";
    }
}

bool LinkTomographyAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyAck *pp = (LinkTomographyAck *)object; (void)pp;
    switch (field) {
        case 1: pp->setQnic_index(string2long(value)); return true;
        default: return false;
    }
}

const char *LinkTomographyAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(QNIC_type));
        default: return nullptr;
    };
}

void *LinkTomographyAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyAck *pp = (LinkTomographyAck *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getQnic_type()); break;
        default: return nullptr;
    }
}

Register_Class(LinkTomographyResult)

LinkTomographyResult::LinkTomographyResult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->Output_is_plus = false;
    this->Basis = 0;
    this->count_id = 0;
    this->partner_address = 0;
    this->finish = -1;
    this->max_count = 0;
    this->GOD_clean = 0;
}

LinkTomographyResult::LinkTomographyResult(const LinkTomographyResult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

LinkTomographyResult::~LinkTomographyResult()
{
}

LinkTomographyResult& LinkTomographyResult::operator=(const LinkTomographyResult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void LinkTomographyResult::copy(const LinkTomographyResult& other)
{
    this->Output_is_plus = other.Output_is_plus;
    this->Basis = other.Basis;
    this->count_id = other.count_id;
    this->partner_address = other.partner_address;
    this->finish = other.finish;
    this->max_count = other.max_count;
    this->GOD_clean = other.GOD_clean;
}

void LinkTomographyResult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->Output_is_plus);
    doParsimPacking(b,this->Basis);
    doParsimPacking(b,this->count_id);
    doParsimPacking(b,this->partner_address);
    doParsimPacking(b,this->finish);
    doParsimPacking(b,this->max_count);
    doParsimPacking(b,this->GOD_clean);
}

void LinkTomographyResult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->Output_is_plus);
    doParsimUnpacking(b,this->Basis);
    doParsimUnpacking(b,this->count_id);
    doParsimUnpacking(b,this->partner_address);
    doParsimUnpacking(b,this->finish);
    doParsimUnpacking(b,this->max_count);
    doParsimUnpacking(b,this->GOD_clean);
}

bool LinkTomographyResult::getOutput_is_plus() const
{
    return this->Output_is_plus;
}

void LinkTomographyResult::setOutput_is_plus(bool Output_is_plus)
{
    this->Output_is_plus = Output_is_plus;
}

char LinkTomographyResult::getBasis() const
{
    return this->Basis;
}

void LinkTomographyResult::setBasis(char Basis)
{
    this->Basis = Basis;
}

int LinkTomographyResult::getCount_id() const
{
    return this->count_id;
}

void LinkTomographyResult::setCount_id(int count_id)
{
    this->count_id = count_id;
}

int LinkTomographyResult::getPartner_address() const
{
    return this->partner_address;
}

void LinkTomographyResult::setPartner_address(int partner_address)
{
    this->partner_address = partner_address;
}

::omnetpp::simtime_t LinkTomographyResult::getFinish() const
{
    return this->finish;
}

void LinkTomographyResult::setFinish(::omnetpp::simtime_t finish)
{
    this->finish = finish;
}

int LinkTomographyResult::getMax_count() const
{
    return this->max_count;
}

void LinkTomographyResult::setMax_count(int max_count)
{
    this->max_count = max_count;
}

char LinkTomographyResult::getGOD_clean() const
{
    return this->GOD_clean;
}

void LinkTomographyResult::setGOD_clean(char GOD_clean)
{
    this->GOD_clean = GOD_clean;
}

class LinkTomographyResultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LinkTomographyResultDescriptor();
    virtual ~LinkTomographyResultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LinkTomographyResultDescriptor)

LinkTomographyResultDescriptor::LinkTomographyResultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::LinkTomographyResult", "quisp::messages::header")
{
    propertynames = nullptr;
}

LinkTomographyResultDescriptor::~LinkTomographyResultDescriptor()
{
    delete[] propertynames;
}

bool LinkTomographyResultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LinkTomographyResult *>(obj)!=nullptr;
}

const char **LinkTomographyResultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkTomographyResultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkTomographyResultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int LinkTomographyResultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *LinkTomographyResultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Output_is_plus",
        "Basis",
        "count_id",
        "partner_address",
        "finish",
        "max_count",
        "GOD_clean",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int LinkTomographyResultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Output_is_plus")==0) return base+0;
    if (fieldName[0]=='B' && strcmp(fieldName, "Basis")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "count_id")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "partner_address")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "finish")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "max_count")==0) return base+5;
    if (fieldName[0]=='G' && strcmp(fieldName, "GOD_clean")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkTomographyResultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "char",
        "int",
        "int",
        "simtime_t",
        "int",
        "char",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **LinkTomographyResultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LinkTomographyResultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LinkTomographyResultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyResult *pp = (LinkTomographyResult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LinkTomographyResultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyResult *pp = (LinkTomographyResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkTomographyResultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyResult *pp = (LinkTomographyResult *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getOutput_is_plus());
        case 1: return long2string(pp->getBasis());
        case 2: return long2string(pp->getCount_id());
        case 3: return long2string(pp->getPartner_address());
        case 4: return simtime2string(pp->getFinish());
        case 5: return long2string(pp->getMax_count());
        case 6: return long2string(pp->getGOD_clean());
        default: return "";
    }
}

bool LinkTomographyResultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyResult *pp = (LinkTomographyResult *)object; (void)pp;
    switch (field) {
        case 0: pp->setOutput_is_plus(string2bool(value)); return true;
        case 1: pp->setBasis(string2long(value)); return true;
        case 2: pp->setCount_id(string2long(value)); return true;
        case 3: pp->setPartner_address(string2long(value)); return true;
        case 4: pp->setFinish(string2simtime(value)); return true;
        case 5: pp->setMax_count(string2long(value)); return true;
        case 6: pp->setGOD_clean(string2long(value)); return true;
        default: return false;
    }
}

const char *LinkTomographyResultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *LinkTomographyResultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LinkTomographyResult *pp = (LinkTomographyResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PurificationResult)

PurificationResult::PurificationResult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->Output_is_plus = false;
    this->ruleset_id = 0;
    this->rule_id = 0;
    this->action_index = 0;
}

PurificationResult::PurificationResult(const PurificationResult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

PurificationResult::~PurificationResult()
{
}

PurificationResult& PurificationResult::operator=(const PurificationResult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void PurificationResult::copy(const PurificationResult& other)
{
    this->Output_is_plus = other.Output_is_plus;
    this->ruleset_id = other.ruleset_id;
    this->rule_id = other.rule_id;
    this->action_index = other.action_index;
    this->entangled_with = other.entangled_with;
}

void PurificationResult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->Output_is_plus);
    doParsimPacking(b,this->ruleset_id);
    doParsimPacking(b,this->rule_id);
    doParsimPacking(b,this->action_index);
    doParsimPacking(b,this->entangled_with);
}

void PurificationResult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->Output_is_plus);
    doParsimUnpacking(b,this->ruleset_id);
    doParsimUnpacking(b,this->rule_id);
    doParsimUnpacking(b,this->action_index);
    doParsimUnpacking(b,this->entangled_with);
}

bool PurificationResult::getOutput_is_plus() const
{
    return this->Output_is_plus;
}

void PurificationResult::setOutput_is_plus(bool Output_is_plus)
{
    this->Output_is_plus = Output_is_plus;
}

unsigned long PurificationResult::getRuleset_id() const
{
    return this->ruleset_id;
}

void PurificationResult::setRuleset_id(unsigned long ruleset_id)
{
    this->ruleset_id = ruleset_id;
}

int PurificationResult::getRule_id() const
{
    return this->rule_id;
}

void PurificationResult::setRule_id(int rule_id)
{
    this->rule_id = rule_id;
}

int PurificationResult::getAction_index() const
{
    return this->action_index;
}

void PurificationResult::setAction_index(int action_index)
{
    this->action_index = action_index;
}

GOD_statQubitPtr& PurificationResult::getEntangled_with()
{
    return this->entangled_with;
}

void PurificationResult::setEntangled_with(const GOD_statQubitPtr& entangled_with)
{
    this->entangled_with = entangled_with;
}

class PurificationResultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PurificationResultDescriptor();
    virtual ~PurificationResultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(PurificationResultDescriptor)

PurificationResultDescriptor::PurificationResultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::PurificationResult", "quisp::messages::header")
{
    propertynames = nullptr;
}

PurificationResultDescriptor::~PurificationResultDescriptor()
{
    delete[] propertynames;
}

bool PurificationResultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PurificationResult *>(obj)!=nullptr;
}

const char **PurificationResultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PurificationResultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PurificationResultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int PurificationResultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *PurificationResultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Output_is_plus",
        "ruleset_id",
        "rule_id",
        "action_index",
        "entangled_with",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int PurificationResultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Output_is_plus")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "ruleset_id")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "rule_id")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "action_index")==0) return base+3;
    if (fieldName[0]=='e' && strcmp(fieldName, "entangled_with")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PurificationResultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "unsigned long",
        "int",
        "int",
        "GOD_statQubitPtr",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **PurificationResultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *PurificationResultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int PurificationResultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PurificationResult *pp = (PurificationResult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PurificationResultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PurificationResult *pp = (PurificationResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PurificationResultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PurificationResult *pp = (PurificationResult *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getOutput_is_plus());
        case 1: return ulong2string(pp->getRuleset_id());
        case 2: return long2string(pp->getRule_id());
        case 3: return long2string(pp->getAction_index());
        case 4: {std::stringstream out; out << pp->getEntangled_with(); return out.str();}
        default: return "";
    }
}

bool PurificationResultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PurificationResult *pp = (PurificationResult *)object; (void)pp;
    switch (field) {
        case 0: pp->setOutput_is_plus(string2bool(value)); return true;
        case 1: pp->setRuleset_id(string2ulong(value)); return true;
        case 2: pp->setRule_id(string2long(value)); return true;
        case 3: pp->setAction_index(string2long(value)); return true;
        default: return false;
    }
}

const char *PurificationResultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(GOD_statQubitPtr));
        default: return nullptr;
    };
}

void *PurificationResultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PurificationResult *pp = (PurificationResult *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getEntangled_with()); break;
        default: return nullptr;
    }
}

Register_Class(DoublePurificationResult)

DoublePurificationResult::DoublePurificationResult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->ZOutput_is_plus = false;
    this->XOutput_is_plus = false;
    this->ruleset_id = 0;
    this->rule_id = 0;
    this->action_index = 0;
}

DoublePurificationResult::DoublePurificationResult(const DoublePurificationResult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

DoublePurificationResult::~DoublePurificationResult()
{
}

DoublePurificationResult& DoublePurificationResult::operator=(const DoublePurificationResult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void DoublePurificationResult::copy(const DoublePurificationResult& other)
{
    this->ZOutput_is_plus = other.ZOutput_is_plus;
    this->XOutput_is_plus = other.XOutput_is_plus;
    this->ruleset_id = other.ruleset_id;
    this->rule_id = other.rule_id;
    this->action_index = other.action_index;
    this->entangled_with = other.entangled_with;
}

void DoublePurificationResult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->ZOutput_is_plus);
    doParsimPacking(b,this->XOutput_is_plus);
    doParsimPacking(b,this->ruleset_id);
    doParsimPacking(b,this->rule_id);
    doParsimPacking(b,this->action_index);
    doParsimPacking(b,this->entangled_with);
}

void DoublePurificationResult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->ZOutput_is_plus);
    doParsimUnpacking(b,this->XOutput_is_plus);
    doParsimUnpacking(b,this->ruleset_id);
    doParsimUnpacking(b,this->rule_id);
    doParsimUnpacking(b,this->action_index);
    doParsimUnpacking(b,this->entangled_with);
}

bool DoublePurificationResult::getZOutput_is_plus() const
{
    return this->ZOutput_is_plus;
}

void DoublePurificationResult::setZOutput_is_plus(bool ZOutput_is_plus)
{
    this->ZOutput_is_plus = ZOutput_is_plus;
}

bool DoublePurificationResult::getXOutput_is_plus() const
{
    return this->XOutput_is_plus;
}

void DoublePurificationResult::setXOutput_is_plus(bool XOutput_is_plus)
{
    this->XOutput_is_plus = XOutput_is_plus;
}

unsigned long DoublePurificationResult::getRuleset_id() const
{
    return this->ruleset_id;
}

void DoublePurificationResult::setRuleset_id(unsigned long ruleset_id)
{
    this->ruleset_id = ruleset_id;
}

int DoublePurificationResult::getRule_id() const
{
    return this->rule_id;
}

void DoublePurificationResult::setRule_id(int rule_id)
{
    this->rule_id = rule_id;
}

int DoublePurificationResult::getAction_index() const
{
    return this->action_index;
}

void DoublePurificationResult::setAction_index(int action_index)
{
    this->action_index = action_index;
}

GOD_statQubitPtr& DoublePurificationResult::getEntangled_with()
{
    return this->entangled_with;
}

void DoublePurificationResult::setEntangled_with(const GOD_statQubitPtr& entangled_with)
{
    this->entangled_with = entangled_with;
}

class DoublePurificationResultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DoublePurificationResultDescriptor();
    virtual ~DoublePurificationResultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DoublePurificationResultDescriptor)

DoublePurificationResultDescriptor::DoublePurificationResultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::DoublePurificationResult", "quisp::messages::header")
{
    propertynames = nullptr;
}

DoublePurificationResultDescriptor::~DoublePurificationResultDescriptor()
{
    delete[] propertynames;
}

bool DoublePurificationResultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DoublePurificationResult *>(obj)!=nullptr;
}

const char **DoublePurificationResultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DoublePurificationResultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DoublePurificationResultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int DoublePurificationResultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *DoublePurificationResultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ZOutput_is_plus",
        "XOutput_is_plus",
        "ruleset_id",
        "rule_id",
        "action_index",
        "entangled_with",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int DoublePurificationResultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='Z' && strcmp(fieldName, "ZOutput_is_plus")==0) return base+0;
    if (fieldName[0]=='X' && strcmp(fieldName, "XOutput_is_plus")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "ruleset_id")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "rule_id")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "action_index")==0) return base+4;
    if (fieldName[0]=='e' && strcmp(fieldName, "entangled_with")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DoublePurificationResultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "unsigned long",
        "int",
        "int",
        "GOD_statQubitPtr",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **DoublePurificationResultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DoublePurificationResultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DoublePurificationResultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DoublePurificationResult *pp = (DoublePurificationResult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DoublePurificationResultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DoublePurificationResult *pp = (DoublePurificationResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DoublePurificationResultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DoublePurificationResult *pp = (DoublePurificationResult *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getZOutput_is_plus());
        case 1: return bool2string(pp->getXOutput_is_plus());
        case 2: return ulong2string(pp->getRuleset_id());
        case 3: return long2string(pp->getRule_id());
        case 4: return long2string(pp->getAction_index());
        case 5: {std::stringstream out; out << pp->getEntangled_with(); return out.str();}
        default: return "";
    }
}

bool DoublePurificationResultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DoublePurificationResult *pp = (DoublePurificationResult *)object; (void)pp;
    switch (field) {
        case 0: pp->setZOutput_is_plus(string2bool(value)); return true;
        case 1: pp->setXOutput_is_plus(string2bool(value)); return true;
        case 2: pp->setRuleset_id(string2ulong(value)); return true;
        case 3: pp->setRule_id(string2long(value)); return true;
        case 4: pp->setAction_index(string2long(value)); return true;
        default: return false;
    }
}

const char *DoublePurificationResultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(GOD_statQubitPtr));
        default: return nullptr;
    };
}

void *DoublePurificationResultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DoublePurificationResult *pp = (DoublePurificationResult *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getEntangled_with()); break;
        default: return nullptr;
    }
}

Register_Class(DS_DoublePurificationResult)

DS_DoublePurificationResult::DS_DoublePurificationResult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->ZOutput_is_plus = false;
    this->XOutput_is_plus = false;
    this->DS_ZOutput_is_plus = false;
    this->DS_XOutput_is_plus = false;
    this->ruleset_id = 0;
    this->rule_id = 0;
    this->action_index = 0;
}

DS_DoublePurificationResult::DS_DoublePurificationResult(const DS_DoublePurificationResult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

DS_DoublePurificationResult::~DS_DoublePurificationResult()
{
}

DS_DoublePurificationResult& DS_DoublePurificationResult::operator=(const DS_DoublePurificationResult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void DS_DoublePurificationResult::copy(const DS_DoublePurificationResult& other)
{
    this->ZOutput_is_plus = other.ZOutput_is_plus;
    this->XOutput_is_plus = other.XOutput_is_plus;
    this->DS_ZOutput_is_plus = other.DS_ZOutput_is_plus;
    this->DS_XOutput_is_plus = other.DS_XOutput_is_plus;
    this->ruleset_id = other.ruleset_id;
    this->rule_id = other.rule_id;
    this->action_index = other.action_index;
    this->entangled_with = other.entangled_with;
}

void DS_DoublePurificationResult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->ZOutput_is_plus);
    doParsimPacking(b,this->XOutput_is_plus);
    doParsimPacking(b,this->DS_ZOutput_is_plus);
    doParsimPacking(b,this->DS_XOutput_is_plus);
    doParsimPacking(b,this->ruleset_id);
    doParsimPacking(b,this->rule_id);
    doParsimPacking(b,this->action_index);
    doParsimPacking(b,this->entangled_with);
}

void DS_DoublePurificationResult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->ZOutput_is_plus);
    doParsimUnpacking(b,this->XOutput_is_plus);
    doParsimUnpacking(b,this->DS_ZOutput_is_plus);
    doParsimUnpacking(b,this->DS_XOutput_is_plus);
    doParsimUnpacking(b,this->ruleset_id);
    doParsimUnpacking(b,this->rule_id);
    doParsimUnpacking(b,this->action_index);
    doParsimUnpacking(b,this->entangled_with);
}

bool DS_DoublePurificationResult::getZOutput_is_plus() const
{
    return this->ZOutput_is_plus;
}

void DS_DoublePurificationResult::setZOutput_is_plus(bool ZOutput_is_plus)
{
    this->ZOutput_is_plus = ZOutput_is_plus;
}

bool DS_DoublePurificationResult::getXOutput_is_plus() const
{
    return this->XOutput_is_plus;
}

void DS_DoublePurificationResult::setXOutput_is_plus(bool XOutput_is_plus)
{
    this->XOutput_is_plus = XOutput_is_plus;
}

bool DS_DoublePurificationResult::getDS_ZOutput_is_plus() const
{
    return this->DS_ZOutput_is_plus;
}

void DS_DoublePurificationResult::setDS_ZOutput_is_plus(bool DS_ZOutput_is_plus)
{
    this->DS_ZOutput_is_plus = DS_ZOutput_is_plus;
}

bool DS_DoublePurificationResult::getDS_XOutput_is_plus() const
{
    return this->DS_XOutput_is_plus;
}

void DS_DoublePurificationResult::setDS_XOutput_is_plus(bool DS_XOutput_is_plus)
{
    this->DS_XOutput_is_plus = DS_XOutput_is_plus;
}

unsigned long DS_DoublePurificationResult::getRuleset_id() const
{
    return this->ruleset_id;
}

void DS_DoublePurificationResult::setRuleset_id(unsigned long ruleset_id)
{
    this->ruleset_id = ruleset_id;
}

int DS_DoublePurificationResult::getRule_id() const
{
    return this->rule_id;
}

void DS_DoublePurificationResult::setRule_id(int rule_id)
{
    this->rule_id = rule_id;
}

int DS_DoublePurificationResult::getAction_index() const
{
    return this->action_index;
}

void DS_DoublePurificationResult::setAction_index(int action_index)
{
    this->action_index = action_index;
}

GOD_statQubitPtr& DS_DoublePurificationResult::getEntangled_with()
{
    return this->entangled_with;
}

void DS_DoublePurificationResult::setEntangled_with(const GOD_statQubitPtr& entangled_with)
{
    this->entangled_with = entangled_with;
}

class DS_DoublePurificationResultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DS_DoublePurificationResultDescriptor();
    virtual ~DS_DoublePurificationResultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DS_DoublePurificationResultDescriptor)

DS_DoublePurificationResultDescriptor::DS_DoublePurificationResultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::DS_DoublePurificationResult", "quisp::messages::header")
{
    propertynames = nullptr;
}

DS_DoublePurificationResultDescriptor::~DS_DoublePurificationResultDescriptor()
{
    delete[] propertynames;
}

bool DS_DoublePurificationResultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DS_DoublePurificationResult *>(obj)!=nullptr;
}

const char **DS_DoublePurificationResultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DS_DoublePurificationResultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DS_DoublePurificationResultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int DS_DoublePurificationResultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *DS_DoublePurificationResultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ZOutput_is_plus",
        "XOutput_is_plus",
        "DS_ZOutput_is_plus",
        "DS_XOutput_is_plus",
        "ruleset_id",
        "rule_id",
        "action_index",
        "entangled_with",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int DS_DoublePurificationResultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='Z' && strcmp(fieldName, "ZOutput_is_plus")==0) return base+0;
    if (fieldName[0]=='X' && strcmp(fieldName, "XOutput_is_plus")==0) return base+1;
    if (fieldName[0]=='D' && strcmp(fieldName, "DS_ZOutput_is_plus")==0) return base+2;
    if (fieldName[0]=='D' && strcmp(fieldName, "DS_XOutput_is_plus")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "ruleset_id")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "rule_id")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "action_index")==0) return base+6;
    if (fieldName[0]=='e' && strcmp(fieldName, "entangled_with")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DS_DoublePurificationResultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "unsigned long",
        "int",
        "int",
        "GOD_statQubitPtr",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **DS_DoublePurificationResultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DS_DoublePurificationResultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DS_DoublePurificationResultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationResult *pp = (DS_DoublePurificationResult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DS_DoublePurificationResultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationResult *pp = (DS_DoublePurificationResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DS_DoublePurificationResultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationResult *pp = (DS_DoublePurificationResult *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getZOutput_is_plus());
        case 1: return bool2string(pp->getXOutput_is_plus());
        case 2: return bool2string(pp->getDS_ZOutput_is_plus());
        case 3: return bool2string(pp->getDS_XOutput_is_plus());
        case 4: return ulong2string(pp->getRuleset_id());
        case 5: return long2string(pp->getRule_id());
        case 6: return long2string(pp->getAction_index());
        case 7: {std::stringstream out; out << pp->getEntangled_with(); return out.str();}
        default: return "";
    }
}

bool DS_DoublePurificationResultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationResult *pp = (DS_DoublePurificationResult *)object; (void)pp;
    switch (field) {
        case 0: pp->setZOutput_is_plus(string2bool(value)); return true;
        case 1: pp->setXOutput_is_plus(string2bool(value)); return true;
        case 2: pp->setDS_ZOutput_is_plus(string2bool(value)); return true;
        case 3: pp->setDS_XOutput_is_plus(string2bool(value)); return true;
        case 4: pp->setRuleset_id(string2ulong(value)); return true;
        case 5: pp->setRule_id(string2long(value)); return true;
        case 6: pp->setAction_index(string2long(value)); return true;
        default: return false;
    }
}

const char *DS_DoublePurificationResultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(GOD_statQubitPtr));
        default: return nullptr;
    };
}

void *DS_DoublePurificationResultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationResult *pp = (DS_DoublePurificationResult *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getEntangled_with()); break;
        default: return nullptr;
    }
}

Register_Class(DS_DoublePurificationSecondResult)

DS_DoublePurificationSecondResult::DS_DoublePurificationSecondResult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->ZOutput_is_plus = false;
    this->XOutput_is_plus = false;
    this->DS_Output_is_plus = false;
    this->ruleset_id = 0;
    this->rule_id = 0;
    this->action_index = 0;
}

DS_DoublePurificationSecondResult::DS_DoublePurificationSecondResult(const DS_DoublePurificationSecondResult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

DS_DoublePurificationSecondResult::~DS_DoublePurificationSecondResult()
{
}

DS_DoublePurificationSecondResult& DS_DoublePurificationSecondResult::operator=(const DS_DoublePurificationSecondResult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void DS_DoublePurificationSecondResult::copy(const DS_DoublePurificationSecondResult& other)
{
    this->ZOutput_is_plus = other.ZOutput_is_plus;
    this->XOutput_is_plus = other.XOutput_is_plus;
    this->DS_Output_is_plus = other.DS_Output_is_plus;
    this->ruleset_id = other.ruleset_id;
    this->rule_id = other.rule_id;
    this->action_index = other.action_index;
    this->entangled_with = other.entangled_with;
}

void DS_DoublePurificationSecondResult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->ZOutput_is_plus);
    doParsimPacking(b,this->XOutput_is_plus);
    doParsimPacking(b,this->DS_Output_is_plus);
    doParsimPacking(b,this->ruleset_id);
    doParsimPacking(b,this->rule_id);
    doParsimPacking(b,this->action_index);
    doParsimPacking(b,this->entangled_with);
}

void DS_DoublePurificationSecondResult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->ZOutput_is_plus);
    doParsimUnpacking(b,this->XOutput_is_plus);
    doParsimUnpacking(b,this->DS_Output_is_plus);
    doParsimUnpacking(b,this->ruleset_id);
    doParsimUnpacking(b,this->rule_id);
    doParsimUnpacking(b,this->action_index);
    doParsimUnpacking(b,this->entangled_with);
}

bool DS_DoublePurificationSecondResult::getZOutput_is_plus() const
{
    return this->ZOutput_is_plus;
}

void DS_DoublePurificationSecondResult::setZOutput_is_plus(bool ZOutput_is_plus)
{
    this->ZOutput_is_plus = ZOutput_is_plus;
}

bool DS_DoublePurificationSecondResult::getXOutput_is_plus() const
{
    return this->XOutput_is_plus;
}

void DS_DoublePurificationSecondResult::setXOutput_is_plus(bool XOutput_is_plus)
{
    this->XOutput_is_plus = XOutput_is_plus;
}

bool DS_DoublePurificationSecondResult::getDS_Output_is_plus() const
{
    return this->DS_Output_is_plus;
}

void DS_DoublePurificationSecondResult::setDS_Output_is_plus(bool DS_Output_is_plus)
{
    this->DS_Output_is_plus = DS_Output_is_plus;
}

unsigned long DS_DoublePurificationSecondResult::getRuleset_id() const
{
    return this->ruleset_id;
}

void DS_DoublePurificationSecondResult::setRuleset_id(unsigned long ruleset_id)
{
    this->ruleset_id = ruleset_id;
}

int DS_DoublePurificationSecondResult::getRule_id() const
{
    return this->rule_id;
}

void DS_DoublePurificationSecondResult::setRule_id(int rule_id)
{
    this->rule_id = rule_id;
}

int DS_DoublePurificationSecondResult::getAction_index() const
{
    return this->action_index;
}

void DS_DoublePurificationSecondResult::setAction_index(int action_index)
{
    this->action_index = action_index;
}

GOD_statQubitPtr& DS_DoublePurificationSecondResult::getEntangled_with()
{
    return this->entangled_with;
}

void DS_DoublePurificationSecondResult::setEntangled_with(const GOD_statQubitPtr& entangled_with)
{
    this->entangled_with = entangled_with;
}

class DS_DoublePurificationSecondResultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DS_DoublePurificationSecondResultDescriptor();
    virtual ~DS_DoublePurificationSecondResultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DS_DoublePurificationSecondResultDescriptor)

DS_DoublePurificationSecondResultDescriptor::DS_DoublePurificationSecondResultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::DS_DoublePurificationSecondResult", "quisp::messages::header")
{
    propertynames = nullptr;
}

DS_DoublePurificationSecondResultDescriptor::~DS_DoublePurificationSecondResultDescriptor()
{
    delete[] propertynames;
}

bool DS_DoublePurificationSecondResultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DS_DoublePurificationSecondResult *>(obj)!=nullptr;
}

const char **DS_DoublePurificationSecondResultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DS_DoublePurificationSecondResultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DS_DoublePurificationSecondResultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int DS_DoublePurificationSecondResultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *DS_DoublePurificationSecondResultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ZOutput_is_plus",
        "XOutput_is_plus",
        "DS_Output_is_plus",
        "ruleset_id",
        "rule_id",
        "action_index",
        "entangled_with",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int DS_DoublePurificationSecondResultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='Z' && strcmp(fieldName, "ZOutput_is_plus")==0) return base+0;
    if (fieldName[0]=='X' && strcmp(fieldName, "XOutput_is_plus")==0) return base+1;
    if (fieldName[0]=='D' && strcmp(fieldName, "DS_Output_is_plus")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "ruleset_id")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "rule_id")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "action_index")==0) return base+5;
    if (fieldName[0]=='e' && strcmp(fieldName, "entangled_with")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DS_DoublePurificationSecondResultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "unsigned long",
        "int",
        "int",
        "GOD_statQubitPtr",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **DS_DoublePurificationSecondResultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DS_DoublePurificationSecondResultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DS_DoublePurificationSecondResultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationSecondResult *pp = (DS_DoublePurificationSecondResult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DS_DoublePurificationSecondResultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationSecondResult *pp = (DS_DoublePurificationSecondResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DS_DoublePurificationSecondResultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationSecondResult *pp = (DS_DoublePurificationSecondResult *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getZOutput_is_plus());
        case 1: return bool2string(pp->getXOutput_is_plus());
        case 2: return bool2string(pp->getDS_Output_is_plus());
        case 3: return ulong2string(pp->getRuleset_id());
        case 4: return long2string(pp->getRule_id());
        case 5: return long2string(pp->getAction_index());
        case 6: {std::stringstream out; out << pp->getEntangled_with(); return out.str();}
        default: return "";
    }
}

bool DS_DoublePurificationSecondResultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationSecondResult *pp = (DS_DoublePurificationSecondResult *)object; (void)pp;
    switch (field) {
        case 0: pp->setZOutput_is_plus(string2bool(value)); return true;
        case 1: pp->setXOutput_is_plus(string2bool(value)); return true;
        case 2: pp->setDS_Output_is_plus(string2bool(value)); return true;
        case 3: pp->setRuleset_id(string2ulong(value)); return true;
        case 4: pp->setRule_id(string2long(value)); return true;
        case 5: pp->setAction_index(string2long(value)); return true;
        default: return false;
    }
}

const char *DS_DoublePurificationSecondResultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 6: return omnetpp::opp_typename(typeid(GOD_statQubitPtr));
        default: return nullptr;
    };
}

void *DS_DoublePurificationSecondResultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DS_DoublePurificationSecondResult *pp = (DS_DoublePurificationSecondResult *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getEntangled_with()); break;
        default: return nullptr;
    }
}

Register_Class(ConditionNotSatisfied)

ConditionNotSatisfied::ConditionNotSatisfied(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
}

ConditionNotSatisfied::ConditionNotSatisfied(const ConditionNotSatisfied& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ConditionNotSatisfied::~ConditionNotSatisfied()
{
}

ConditionNotSatisfied& ConditionNotSatisfied::operator=(const ConditionNotSatisfied& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ConditionNotSatisfied::copy(const ConditionNotSatisfied& other)
{
}

void ConditionNotSatisfied::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
}

void ConditionNotSatisfied::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
}

class ConditionNotSatisfiedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ConditionNotSatisfiedDescriptor();
    virtual ~ConditionNotSatisfiedDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ConditionNotSatisfiedDescriptor)

ConditionNotSatisfiedDescriptor::ConditionNotSatisfiedDescriptor() : omnetpp::cClassDescriptor("quisp::messages::ConditionNotSatisfied", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

ConditionNotSatisfiedDescriptor::~ConditionNotSatisfiedDescriptor()
{
    delete[] propertynames;
}

bool ConditionNotSatisfiedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ConditionNotSatisfied *>(obj)!=nullptr;
}

const char **ConditionNotSatisfiedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ConditionNotSatisfiedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ConditionNotSatisfiedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int ConditionNotSatisfiedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *ConditionNotSatisfiedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int ConditionNotSatisfiedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ConditionNotSatisfiedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **ConditionNotSatisfiedDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ConditionNotSatisfiedDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ConditionNotSatisfiedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ConditionNotSatisfied *pp = (ConditionNotSatisfied *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ConditionNotSatisfiedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConditionNotSatisfied *pp = (ConditionNotSatisfied *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ConditionNotSatisfiedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConditionNotSatisfied *pp = (ConditionNotSatisfied *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ConditionNotSatisfiedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ConditionNotSatisfied *pp = (ConditionNotSatisfied *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ConditionNotSatisfiedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *ConditionNotSatisfiedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ConditionNotSatisfied *pp = (ConditionNotSatisfied *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ConnectionSetupResponse)

ConnectionSetupResponse::ConnectionSetupResponse(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->actual_srcAddr = 0;
    this->actual_destAddr = 0;
    this->RuleSet_id = 0;
    this->application_type = 0;
    stack_of_QNodeIndexes_arraysize = 0;
    this->stack_of_QNodeIndexes = 0;
}

ConnectionSetupResponse::ConnectionSetupResponse(const ConnectionSetupResponse& other) : ::quisp::messages::header(other)
{
    stack_of_QNodeIndexes_arraysize = 0;
    this->stack_of_QNodeIndexes = 0;
    copy(other);
}

ConnectionSetupResponse::~ConnectionSetupResponse()
{
    delete [] this->stack_of_QNodeIndexes;
}

ConnectionSetupResponse& ConnectionSetupResponse::operator=(const ConnectionSetupResponse& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void ConnectionSetupResponse::copy(const ConnectionSetupResponse& other)
{
    this->actual_srcAddr = other.actual_srcAddr;
    this->actual_destAddr = other.actual_destAddr;
    this->RuleSet_id = other.RuleSet_id;
    this->RuleSet = other.RuleSet;
    this->application_type = other.application_type;
    delete [] this->stack_of_QNodeIndexes;
    this->stack_of_QNodeIndexes = (other.stack_of_QNodeIndexes_arraysize==0) ? nullptr : new int[other.stack_of_QNodeIndexes_arraysize];
    stack_of_QNodeIndexes_arraysize = other.stack_of_QNodeIndexes_arraysize;
    for (unsigned int i=0; i<stack_of_QNodeIndexes_arraysize; i++)
        this->stack_of_QNodeIndexes[i] = other.stack_of_QNodeIndexes[i];
}

void ConnectionSetupResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->actual_srcAddr);
    doParsimPacking(b,this->actual_destAddr);
    doParsimPacking(b,this->RuleSet_id);
    doParsimPacking(b,this->RuleSet);
    doParsimPacking(b,this->application_type);
    b->pack(stack_of_QNodeIndexes_arraysize);
    doParsimArrayPacking(b,this->stack_of_QNodeIndexes,stack_of_QNodeIndexes_arraysize);
}

void ConnectionSetupResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->actual_srcAddr);
    doParsimUnpacking(b,this->actual_destAddr);
    doParsimUnpacking(b,this->RuleSet_id);
    doParsimUnpacking(b,this->RuleSet);
    doParsimUnpacking(b,this->application_type);
    delete [] this->stack_of_QNodeIndexes;
    b->unpack(stack_of_QNodeIndexes_arraysize);
    if (stack_of_QNodeIndexes_arraysize==0) {
        this->stack_of_QNodeIndexes = 0;
    } else {
        this->stack_of_QNodeIndexes = new int[stack_of_QNodeIndexes_arraysize];
        doParsimArrayUnpacking(b,this->stack_of_QNodeIndexes,stack_of_QNodeIndexes_arraysize);
    }
}

int ConnectionSetupResponse::getActual_srcAddr() const
{
    return this->actual_srcAddr;
}

void ConnectionSetupResponse::setActual_srcAddr(int actual_srcAddr)
{
    this->actual_srcAddr = actual_srcAddr;
}

int ConnectionSetupResponse::getActual_destAddr() const
{
    return this->actual_destAddr;
}

void ConnectionSetupResponse::setActual_destAddr(int actual_destAddr)
{
    this->actual_destAddr = actual_destAddr;
}

unsigned long ConnectionSetupResponse::getRuleSet_id() const
{
    return this->RuleSet_id;
}

void ConnectionSetupResponse::setRuleSet_id(unsigned long RuleSet_id)
{
    this->RuleSet_id = RuleSet_id;
}

RuleSetField& ConnectionSetupResponse::getRuleSet()
{
    return this->RuleSet;
}

void ConnectionSetupResponse::setRuleSet(const RuleSetField& RuleSet)
{
    this->RuleSet = RuleSet;
}

int ConnectionSetupResponse::getApplication_type() const
{
    return this->application_type;
}

void ConnectionSetupResponse::setApplication_type(int application_type)
{
    this->application_type = application_type;
}

void ConnectionSetupResponse::setStack_of_QNodeIndexesArraySize(unsigned int size)
{
    int *stack_of_QNodeIndexes2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = stack_of_QNodeIndexes_arraysize < size ? stack_of_QNodeIndexes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        stack_of_QNodeIndexes2[i] = this->stack_of_QNodeIndexes[i];
    for (unsigned int i=sz; i<size; i++)
        stack_of_QNodeIndexes2[i] = 0;
    stack_of_QNodeIndexes_arraysize = size;
    delete [] this->stack_of_QNodeIndexes;
    this->stack_of_QNodeIndexes = stack_of_QNodeIndexes2;
}

unsigned int ConnectionSetupResponse::getStack_of_QNodeIndexesArraySize() const
{
    return stack_of_QNodeIndexes_arraysize;
}

int ConnectionSetupResponse::getStack_of_QNodeIndexes(unsigned int k) const
{
    if (k>=stack_of_QNodeIndexes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_QNodeIndexes_arraysize, k);
    return this->stack_of_QNodeIndexes[k];
}

void ConnectionSetupResponse::setStack_of_QNodeIndexes(unsigned int k, int stack_of_QNodeIndexes)
{
    if (k>=stack_of_QNodeIndexes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", stack_of_QNodeIndexes_arraysize, k);
    this->stack_of_QNodeIndexes[k] = stack_of_QNodeIndexes;
}

class ConnectionSetupResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ConnectionSetupResponseDescriptor();
    virtual ~ConnectionSetupResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ConnectionSetupResponseDescriptor)

ConnectionSetupResponseDescriptor::ConnectionSetupResponseDescriptor() : omnetpp::cClassDescriptor("quisp::messages::ConnectionSetupResponse", "quisp::messages::header")
{
    propertynames = nullptr;
}

ConnectionSetupResponseDescriptor::~ConnectionSetupResponseDescriptor()
{
    delete[] propertynames;
}

bool ConnectionSetupResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ConnectionSetupResponse *>(obj)!=nullptr;
}

const char **ConnectionSetupResponseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ConnectionSetupResponseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ConnectionSetupResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int ConnectionSetupResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *ConnectionSetupResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "actual_srcAddr",
        "actual_destAddr",
        "RuleSet_id",
        "RuleSet",
        "application_type",
        "stack_of_QNodeIndexes",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int ConnectionSetupResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "actual_srcAddr")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "actual_destAddr")==0) return base+1;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet_id")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "application_type")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "stack_of_QNodeIndexes")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ConnectionSetupResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "unsigned long",
        "RuleSetField",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **ConnectionSetupResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ConnectionSetupResponseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ConnectionSetupResponseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupResponse *pp = (ConnectionSetupResponse *)object; (void)pp;
    switch (field) {
        case 5: return pp->getStack_of_QNodeIndexesArraySize();
        default: return 0;
    }
}

const char *ConnectionSetupResponseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupResponse *pp = (ConnectionSetupResponse *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ConnectionSetupResponseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupResponse *pp = (ConnectionSetupResponse *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getActual_srcAddr());
        case 1: return long2string(pp->getActual_destAddr());
        case 2: return ulong2string(pp->getRuleSet_id());
        case 3: {std::stringstream out; out << pp->getRuleSet(); return out.str();}
        case 4: return long2string(pp->getApplication_type());
        case 5: return long2string(pp->getStack_of_QNodeIndexes(i));
        default: return "";
    }
}

bool ConnectionSetupResponseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupResponse *pp = (ConnectionSetupResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setActual_srcAddr(string2long(value)); return true;
        case 1: pp->setActual_destAddr(string2long(value)); return true;
        case 2: pp->setRuleSet_id(string2ulong(value)); return true;
        case 4: pp->setApplication_type(string2long(value)); return true;
        case 5: pp->setStack_of_QNodeIndexes(i,string2long(value)); return true;
        default: return false;
    }
}

const char *ConnectionSetupResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(RuleSetField));
        default: return nullptr;
    };
}

void *ConnectionSetupResponseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ConnectionSetupResponse *pp = (ConnectionSetupResponse *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getRuleSet()); break;
        default: return nullptr;
    }
}

Register_Class(BSMtimingNotifier)

BSMtimingNotifier::BSMtimingNotifier(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->timing_at = 0;
    this->accepted_photons_per_sec = 0;
    this->interval = 0;
    this->number_of_qubits = 0;
    this->internal_qnic_index = -1;
    this->internal_qnic_address = -1;
}

BSMtimingNotifier::BSMtimingNotifier(const BSMtimingNotifier& other) : ::quisp::messages::header(other)
{
    copy(other);
}

BSMtimingNotifier::~BSMtimingNotifier()
{
}

BSMtimingNotifier& BSMtimingNotifier::operator=(const BSMtimingNotifier& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void BSMtimingNotifier::copy(const BSMtimingNotifier& other)
{
    this->timing_at = other.timing_at;
    this->accepted_photons_per_sec = other.accepted_photons_per_sec;
    this->interval = other.interval;
    this->number_of_qubits = other.number_of_qubits;
    this->internal_qnic_index = other.internal_qnic_index;
    this->internal_qnic_address = other.internal_qnic_address;
}

void BSMtimingNotifier::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->timing_at);
    doParsimPacking(b,this->accepted_photons_per_sec);
    doParsimPacking(b,this->interval);
    doParsimPacking(b,this->number_of_qubits);
    doParsimPacking(b,this->internal_qnic_index);
    doParsimPacking(b,this->internal_qnic_address);
}

void BSMtimingNotifier::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->timing_at);
    doParsimUnpacking(b,this->accepted_photons_per_sec);
    doParsimUnpacking(b,this->interval);
    doParsimUnpacking(b,this->number_of_qubits);
    doParsimUnpacking(b,this->internal_qnic_index);
    doParsimUnpacking(b,this->internal_qnic_address);
}

::omnetpp::simtime_t BSMtimingNotifier::getTiming_at() const
{
    return this->timing_at;
}

void BSMtimingNotifier::setTiming_at(::omnetpp::simtime_t timing_at)
{
    this->timing_at = timing_at;
}

int BSMtimingNotifier::getAccepted_photons_per_sec() const
{
    return this->accepted_photons_per_sec;
}

void BSMtimingNotifier::setAccepted_photons_per_sec(int accepted_photons_per_sec)
{
    this->accepted_photons_per_sec = accepted_photons_per_sec;
}

double BSMtimingNotifier::getInterval() const
{
    return this->interval;
}

void BSMtimingNotifier::setInterval(double interval)
{
    this->interval = interval;
}

int BSMtimingNotifier::getNumber_of_qubits() const
{
    return this->number_of_qubits;
}

void BSMtimingNotifier::setNumber_of_qubits(int number_of_qubits)
{
    this->number_of_qubits = number_of_qubits;
}

int BSMtimingNotifier::getInternal_qnic_index() const
{
    return this->internal_qnic_index;
}

void BSMtimingNotifier::setInternal_qnic_index(int internal_qnic_index)
{
    this->internal_qnic_index = internal_qnic_index;
}

int BSMtimingNotifier::getInternal_qnic_address() const
{
    return this->internal_qnic_address;
}

void BSMtimingNotifier::setInternal_qnic_address(int internal_qnic_address)
{
    this->internal_qnic_address = internal_qnic_address;
}

class BSMtimingNotifierDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BSMtimingNotifierDescriptor();
    virtual ~BSMtimingNotifierDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(BSMtimingNotifierDescriptor)

BSMtimingNotifierDescriptor::BSMtimingNotifierDescriptor() : omnetpp::cClassDescriptor("quisp::messages::BSMtimingNotifier", "quisp::messages::header")
{
    propertynames = nullptr;
}

BSMtimingNotifierDescriptor::~BSMtimingNotifierDescriptor()
{
    delete[] propertynames;
}

bool BSMtimingNotifierDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BSMtimingNotifier *>(obj)!=nullptr;
}

const char **BSMtimingNotifierDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BSMtimingNotifierDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BSMtimingNotifierDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int BSMtimingNotifierDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *BSMtimingNotifierDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timing_at",
        "accepted_photons_per_sec",
        "interval",
        "number_of_qubits",
        "internal_qnic_index",
        "internal_qnic_address",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int BSMtimingNotifierDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timing_at")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "accepted_photons_per_sec")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interval")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "number_of_qubits")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "internal_qnic_index")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "internal_qnic_address")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BSMtimingNotifierDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "int",
        "double",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **BSMtimingNotifierDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BSMtimingNotifierDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BSMtimingNotifierDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BSMtimingNotifier *pp = (BSMtimingNotifier *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BSMtimingNotifierDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSMtimingNotifier *pp = (BSMtimingNotifier *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BSMtimingNotifierDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSMtimingNotifier *pp = (BSMtimingNotifier *)object; (void)pp;
    switch (field) {
        case 0: return simtime2string(pp->getTiming_at());
        case 1: return long2string(pp->getAccepted_photons_per_sec());
        case 2: return double2string(pp->getInterval());
        case 3: return long2string(pp->getNumber_of_qubits());
        case 4: return long2string(pp->getInternal_qnic_index());
        case 5: return long2string(pp->getInternal_qnic_address());
        default: return "";
    }
}

bool BSMtimingNotifierDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BSMtimingNotifier *pp = (BSMtimingNotifier *)object; (void)pp;
    switch (field) {
        case 0: pp->setTiming_at(string2simtime(value)); return true;
        case 1: pp->setAccepted_photons_per_sec(string2long(value)); return true;
        case 2: pp->setInterval(string2double(value)); return true;
        case 3: pp->setNumber_of_qubits(string2long(value)); return true;
        case 4: pp->setInternal_qnic_index(string2long(value)); return true;
        case 5: pp->setInternal_qnic_address(string2long(value)); return true;
        default: return false;
    }
}

const char *BSMtimingNotifierDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *BSMtimingNotifierDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BSMtimingNotifier *pp = (BSMtimingNotifier *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BSAtimeoutChecker)

BSAtimeoutChecker::BSAtimeoutChecker(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->trial_id = 0;
}

BSAtimeoutChecker::BSAtimeoutChecker(const BSAtimeoutChecker& other) : ::quisp::messages::header(other)
{
    copy(other);
}

BSAtimeoutChecker::~BSAtimeoutChecker()
{
}

BSAtimeoutChecker& BSAtimeoutChecker::operator=(const BSAtimeoutChecker& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void BSAtimeoutChecker::copy(const BSAtimeoutChecker& other)
{
    this->trial_id = other.trial_id;
}

void BSAtimeoutChecker::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->trial_id);
}

void BSAtimeoutChecker::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->trial_id);
}

double BSAtimeoutChecker::getTrial_id() const
{
    return this->trial_id;
}

void BSAtimeoutChecker::setTrial_id(double trial_id)
{
    this->trial_id = trial_id;
}

class BSAtimeoutCheckerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BSAtimeoutCheckerDescriptor();
    virtual ~BSAtimeoutCheckerDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(BSAtimeoutCheckerDescriptor)

BSAtimeoutCheckerDescriptor::BSAtimeoutCheckerDescriptor() : omnetpp::cClassDescriptor("quisp::messages::BSAtimeoutChecker", "quisp::messages::header")
{
    propertynames = nullptr;
}

BSAtimeoutCheckerDescriptor::~BSAtimeoutCheckerDescriptor()
{
    delete[] propertynames;
}

bool BSAtimeoutCheckerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BSAtimeoutChecker *>(obj)!=nullptr;
}

const char **BSAtimeoutCheckerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BSAtimeoutCheckerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BSAtimeoutCheckerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BSAtimeoutCheckerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BSAtimeoutCheckerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "trial_id",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BSAtimeoutCheckerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "trial_id")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BSAtimeoutCheckerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **BSAtimeoutCheckerDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BSAtimeoutCheckerDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BSAtimeoutCheckerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BSAtimeoutChecker *pp = (BSAtimeoutChecker *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BSAtimeoutCheckerDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAtimeoutChecker *pp = (BSAtimeoutChecker *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BSAtimeoutCheckerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAtimeoutChecker *pp = (BSAtimeoutChecker *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getTrial_id());
        default: return "";
    }
}

bool BSAtimeoutCheckerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BSAtimeoutChecker *pp = (BSAtimeoutChecker *)object; (void)pp;
    switch (field) {
        case 0: pp->setTrial_id(string2double(value)); return true;
        default: return false;
    }
}

const char *BSAtimeoutCheckerDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *BSAtimeoutCheckerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BSAtimeoutChecker *pp = (BSAtimeoutChecker *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BSAstart)

BSAstart::BSAstart(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
}

BSAstart::BSAstart(const BSAstart& other) : ::quisp::messages::header(other)
{
    copy(other);
}

BSAstart::~BSAstart()
{
}

BSAstart& BSAstart::operator=(const BSAstart& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void BSAstart::copy(const BSAstart& other)
{
}

void BSAstart::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
}

void BSAstart::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
}

class BSAstartDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BSAstartDescriptor();
    virtual ~BSAstartDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(BSAstartDescriptor)

BSAstartDescriptor::BSAstartDescriptor() : omnetpp::cClassDescriptor("quisp::messages::BSAstart", "quisp::messages::header")
{
    propertynames = nullptr;
}

BSAstartDescriptor::~BSAstartDescriptor()
{
    delete[] propertynames;
}

bool BSAstartDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BSAstart *>(obj)!=nullptr;
}

const char **BSAstartDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BSAstartDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BSAstartDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int BSAstartDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *BSAstartDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int BSAstartDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BSAstartDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **BSAstartDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BSAstartDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BSAstartDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BSAstart *pp = (BSAstart *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BSAstartDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAstart *pp = (BSAstart *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BSAstartDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAstart *pp = (BSAstart *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool BSAstartDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BSAstart *pp = (BSAstart *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BSAstartDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *BSAstartDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BSAstart *pp = (BSAstart *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(EPPStimingNotifier)

EPPStimingNotifier::EPPStimingNotifier(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->timing_at = 0;
    this->interval = 0;
    this->number_of_qubits = 0;
    this->internal_qnic = -1;
}

EPPStimingNotifier::EPPStimingNotifier(const EPPStimingNotifier& other) : ::quisp::messages::header(other)
{
    copy(other);
}

EPPStimingNotifier::~EPPStimingNotifier()
{
}

EPPStimingNotifier& EPPStimingNotifier::operator=(const EPPStimingNotifier& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void EPPStimingNotifier::copy(const EPPStimingNotifier& other)
{
    this->timing_at = other.timing_at;
    this->interval = other.interval;
    this->number_of_qubits = other.number_of_qubits;
    this->internal_qnic = other.internal_qnic;
}

void EPPStimingNotifier::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->timing_at);
    doParsimPacking(b,this->interval);
    doParsimPacking(b,this->number_of_qubits);
    doParsimPacking(b,this->internal_qnic);
}

void EPPStimingNotifier::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->timing_at);
    doParsimUnpacking(b,this->interval);
    doParsimUnpacking(b,this->number_of_qubits);
    doParsimUnpacking(b,this->internal_qnic);
}

::omnetpp::simtime_t EPPStimingNotifier::getTiming_at() const
{
    return this->timing_at;
}

void EPPStimingNotifier::setTiming_at(::omnetpp::simtime_t timing_at)
{
    this->timing_at = timing_at;
}

double EPPStimingNotifier::getInterval() const
{
    return this->interval;
}

void EPPStimingNotifier::setInterval(double interval)
{
    this->interval = interval;
}

int EPPStimingNotifier::getNumber_of_qubits() const
{
    return this->number_of_qubits;
}

void EPPStimingNotifier::setNumber_of_qubits(int number_of_qubits)
{
    this->number_of_qubits = number_of_qubits;
}

int EPPStimingNotifier::getInternal_qnic() const
{
    return this->internal_qnic;
}

void EPPStimingNotifier::setInternal_qnic(int internal_qnic)
{
    this->internal_qnic = internal_qnic;
}

class EPPStimingNotifierDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EPPStimingNotifierDescriptor();
    virtual ~EPPStimingNotifierDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EPPStimingNotifierDescriptor)

EPPStimingNotifierDescriptor::EPPStimingNotifierDescriptor() : omnetpp::cClassDescriptor("quisp::messages::EPPStimingNotifier", "quisp::messages::header")
{
    propertynames = nullptr;
}

EPPStimingNotifierDescriptor::~EPPStimingNotifierDescriptor()
{
    delete[] propertynames;
}

bool EPPStimingNotifierDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EPPStimingNotifier *>(obj)!=nullptr;
}

const char **EPPStimingNotifierDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EPPStimingNotifierDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EPPStimingNotifierDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EPPStimingNotifierDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *EPPStimingNotifierDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timing_at",
        "interval",
        "number_of_qubits",
        "internal_qnic",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int EPPStimingNotifierDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timing_at")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interval")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "number_of_qubits")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "internal_qnic")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EPPStimingNotifierDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "double",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **EPPStimingNotifierDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EPPStimingNotifierDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EPPStimingNotifierDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EPPStimingNotifier *pp = (EPPStimingNotifier *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *EPPStimingNotifierDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPPStimingNotifier *pp = (EPPStimingNotifier *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EPPStimingNotifierDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPPStimingNotifier *pp = (EPPStimingNotifier *)object; (void)pp;
    switch (field) {
        case 0: return simtime2string(pp->getTiming_at());
        case 1: return double2string(pp->getInterval());
        case 2: return long2string(pp->getNumber_of_qubits());
        case 3: return long2string(pp->getInternal_qnic());
        default: return "";
    }
}

bool EPPStimingNotifierDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EPPStimingNotifier *pp = (EPPStimingNotifier *)object; (void)pp;
    switch (field) {
        case 0: pp->setTiming_at(string2simtime(value)); return true;
        case 1: pp->setInterval(string2double(value)); return true;
        case 2: pp->setNumber_of_qubits(string2long(value)); return true;
        case 3: pp->setInternal_qnic(string2long(value)); return true;
        default: return false;
    }
}

const char *EPPStimingNotifierDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *EPPStimingNotifierDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EPPStimingNotifier *pp = (EPPStimingNotifier *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(EmitPhotonRequest)

EmitPhotonRequest::EmitPhotonRequest(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->qubit_index = 0;
    this->qnic_index = 0;
    this->qnic_address = 0;
    this->qnic_type = 0;
    this->receiver = false;
    this->first = false;
    this->last = false;
    this->trial = 0;
}

EmitPhotonRequest::EmitPhotonRequest(const EmitPhotonRequest& other) : ::quisp::messages::header(other)
{
    copy(other);
}

EmitPhotonRequest::~EmitPhotonRequest()
{
}

EmitPhotonRequest& EmitPhotonRequest::operator=(const EmitPhotonRequest& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void EmitPhotonRequest::copy(const EmitPhotonRequest& other)
{
    this->qubit_index = other.qubit_index;
    this->qnic_index = other.qnic_index;
    this->qnic_address = other.qnic_address;
    this->qnic_type = other.qnic_type;
    this->receiver = other.receiver;
    this->first = other.first;
    this->last = other.last;
    this->trial = other.trial;
}

void EmitPhotonRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->qubit_index);
    doParsimPacking(b,this->qnic_index);
    doParsimPacking(b,this->qnic_address);
    doParsimPacking(b,this->qnic_type);
    doParsimPacking(b,this->receiver);
    doParsimPacking(b,this->first);
    doParsimPacking(b,this->last);
    doParsimPacking(b,this->trial);
}

void EmitPhotonRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->qubit_index);
    doParsimUnpacking(b,this->qnic_index);
    doParsimUnpacking(b,this->qnic_address);
    doParsimUnpacking(b,this->qnic_type);
    doParsimUnpacking(b,this->receiver);
    doParsimUnpacking(b,this->first);
    doParsimUnpacking(b,this->last);
    doParsimUnpacking(b,this->trial);
}

int EmitPhotonRequest::getQubit_index() const
{
    return this->qubit_index;
}

void EmitPhotonRequest::setQubit_index(int qubit_index)
{
    this->qubit_index = qubit_index;
}

int EmitPhotonRequest::getQnic_index() const
{
    return this->qnic_index;
}

void EmitPhotonRequest::setQnic_index(int qnic_index)
{
    this->qnic_index = qnic_index;
}

int EmitPhotonRequest::getQnic_address() const
{
    return this->qnic_address;
}

void EmitPhotonRequest::setQnic_address(int qnic_address)
{
    this->qnic_address = qnic_address;
}

int EmitPhotonRequest::getQnic_type() const
{
    return this->qnic_type;
}

void EmitPhotonRequest::setQnic_type(int qnic_type)
{
    this->qnic_type = qnic_type;
}

bool EmitPhotonRequest::getReceiver() const
{
    return this->receiver;
}

void EmitPhotonRequest::setReceiver(bool receiver)
{
    this->receiver = receiver;
}

bool EmitPhotonRequest::getFirst() const
{
    return this->first;
}

void EmitPhotonRequest::setFirst(bool first)
{
    this->first = first;
}

bool EmitPhotonRequest::getLast() const
{
    return this->last;
}

void EmitPhotonRequest::setLast(bool last)
{
    this->last = last;
}

int EmitPhotonRequest::getTrial() const
{
    return this->trial;
}

void EmitPhotonRequest::setTrial(int trial)
{
    this->trial = trial;
}

class EmitPhotonRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EmitPhotonRequestDescriptor();
    virtual ~EmitPhotonRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EmitPhotonRequestDescriptor)

EmitPhotonRequestDescriptor::EmitPhotonRequestDescriptor() : omnetpp::cClassDescriptor("quisp::messages::EmitPhotonRequest", "quisp::messages::header")
{
    propertynames = nullptr;
}

EmitPhotonRequestDescriptor::~EmitPhotonRequestDescriptor()
{
    delete[] propertynames;
}

bool EmitPhotonRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EmitPhotonRequest *>(obj)!=nullptr;
}

const char **EmitPhotonRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EmitPhotonRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EmitPhotonRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int EmitPhotonRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *EmitPhotonRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "qubit_index",
        "qnic_index",
        "qnic_address",
        "qnic_type",
        "receiver",
        "first",
        "last",
        "trial",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int EmitPhotonRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qubit_index")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_index")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_address")==0) return base+2;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_type")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiver")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "first")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "last")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "trial")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EmitPhotonRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "bool",
        "bool",
        "bool",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **EmitPhotonRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EmitPhotonRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EmitPhotonRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EmitPhotonRequest *pp = (EmitPhotonRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *EmitPhotonRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EmitPhotonRequest *pp = (EmitPhotonRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EmitPhotonRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EmitPhotonRequest *pp = (EmitPhotonRequest *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getQubit_index());
        case 1: return long2string(pp->getQnic_index());
        case 2: return long2string(pp->getQnic_address());
        case 3: return long2string(pp->getQnic_type());
        case 4: return bool2string(pp->getReceiver());
        case 5: return bool2string(pp->getFirst());
        case 6: return bool2string(pp->getLast());
        case 7: return long2string(pp->getTrial());
        default: return "";
    }
}

bool EmitPhotonRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EmitPhotonRequest *pp = (EmitPhotonRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setQubit_index(string2long(value)); return true;
        case 1: pp->setQnic_index(string2long(value)); return true;
        case 2: pp->setQnic_address(string2long(value)); return true;
        case 3: pp->setQnic_type(string2long(value)); return true;
        case 4: pp->setReceiver(string2bool(value)); return true;
        case 5: pp->setFirst(string2bool(value)); return true;
        case 6: pp->setLast(string2bool(value)); return true;
        case 7: pp->setTrial(string2long(value)); return true;
        default: return false;
    }
}

const char *EmitPhotonRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *EmitPhotonRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EmitPhotonRequest *pp = (EmitPhotonRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SchedulePhotonTransmissionsOnebyOne)

SchedulePhotonTransmissionsOnebyOne::SchedulePhotonTransmissionsOnebyOne(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->qnic_index = -1;
    this->qnic_address = 0;
    this->num_sent = 0;
    this->number_of_qubits_to_send = 0;
    this->trial = 0;
    this->interval = 0;
    this->timing = 0;
    this->internal_hom = 0;
}

SchedulePhotonTransmissionsOnebyOne::SchedulePhotonTransmissionsOnebyOne(const SchedulePhotonTransmissionsOnebyOne& other) : ::quisp::messages::header(other)
{
    copy(other);
}

SchedulePhotonTransmissionsOnebyOne::~SchedulePhotonTransmissionsOnebyOne()
{
}

SchedulePhotonTransmissionsOnebyOne& SchedulePhotonTransmissionsOnebyOne::operator=(const SchedulePhotonTransmissionsOnebyOne& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void SchedulePhotonTransmissionsOnebyOne::copy(const SchedulePhotonTransmissionsOnebyOne& other)
{
    this->qnic_index = other.qnic_index;
    this->qnic_address = other.qnic_address;
    this->num_sent = other.num_sent;
    this->number_of_qubits_to_send = other.number_of_qubits_to_send;
    this->trial = other.trial;
    this->interval = other.interval;
    this->timing = other.timing;
    this->internal_hom = other.internal_hom;
}

void SchedulePhotonTransmissionsOnebyOne::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->qnic_index);
    doParsimPacking(b,this->qnic_address);
    doParsimPacking(b,this->num_sent);
    doParsimPacking(b,this->number_of_qubits_to_send);
    doParsimPacking(b,this->trial);
    doParsimPacking(b,this->interval);
    doParsimPacking(b,this->timing);
    doParsimPacking(b,this->internal_hom);
}

void SchedulePhotonTransmissionsOnebyOne::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->qnic_index);
    doParsimUnpacking(b,this->qnic_address);
    doParsimUnpacking(b,this->num_sent);
    doParsimUnpacking(b,this->number_of_qubits_to_send);
    doParsimUnpacking(b,this->trial);
    doParsimUnpacking(b,this->interval);
    doParsimUnpacking(b,this->timing);
    doParsimUnpacking(b,this->internal_hom);
}

int SchedulePhotonTransmissionsOnebyOne::getQnic_index() const
{
    return this->qnic_index;
}

void SchedulePhotonTransmissionsOnebyOne::setQnic_index(int qnic_index)
{
    this->qnic_index = qnic_index;
}

int SchedulePhotonTransmissionsOnebyOne::getQnic_address() const
{
    return this->qnic_address;
}

void SchedulePhotonTransmissionsOnebyOne::setQnic_address(int qnic_address)
{
    this->qnic_address = qnic_address;
}

int SchedulePhotonTransmissionsOnebyOne::getNum_sent() const
{
    return this->num_sent;
}

void SchedulePhotonTransmissionsOnebyOne::setNum_sent(int num_sent)
{
    this->num_sent = num_sent;
}

int SchedulePhotonTransmissionsOnebyOne::getNumber_of_qubits_to_send() const
{
    return this->number_of_qubits_to_send;
}

void SchedulePhotonTransmissionsOnebyOne::setNumber_of_qubits_to_send(int number_of_qubits_to_send)
{
    this->number_of_qubits_to_send = number_of_qubits_to_send;
}

int SchedulePhotonTransmissionsOnebyOne::getTrial() const
{
    return this->trial;
}

void SchedulePhotonTransmissionsOnebyOne::setTrial(int trial)
{
    this->trial = trial;
}

double SchedulePhotonTransmissionsOnebyOne::getInterval() const
{
    return this->interval;
}

void SchedulePhotonTransmissionsOnebyOne::setInterval(double interval)
{
    this->interval = interval;
}

::omnetpp::simtime_t SchedulePhotonTransmissionsOnebyOne::getTiming() const
{
    return this->timing;
}

void SchedulePhotonTransmissionsOnebyOne::setTiming(::omnetpp::simtime_t timing)
{
    this->timing = timing;
}

int SchedulePhotonTransmissionsOnebyOne::getInternal_hom() const
{
    return this->internal_hom;
}

void SchedulePhotonTransmissionsOnebyOne::setInternal_hom(int internal_hom)
{
    this->internal_hom = internal_hom;
}

class SchedulePhotonTransmissionsOnebyOneDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SchedulePhotonTransmissionsOnebyOneDescriptor();
    virtual ~SchedulePhotonTransmissionsOnebyOneDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(SchedulePhotonTransmissionsOnebyOneDescriptor)

SchedulePhotonTransmissionsOnebyOneDescriptor::SchedulePhotonTransmissionsOnebyOneDescriptor() : omnetpp::cClassDescriptor("quisp::messages::SchedulePhotonTransmissionsOnebyOne", "quisp::messages::header")
{
    propertynames = nullptr;
}

SchedulePhotonTransmissionsOnebyOneDescriptor::~SchedulePhotonTransmissionsOnebyOneDescriptor()
{
    delete[] propertynames;
}

bool SchedulePhotonTransmissionsOnebyOneDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SchedulePhotonTransmissionsOnebyOne *>(obj)!=nullptr;
}

const char **SchedulePhotonTransmissionsOnebyOneDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SchedulePhotonTransmissionsOnebyOneDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "qnic_index",
        "qnic_address",
        "num_sent",
        "number_of_qubits_to_send",
        "trial",
        "interval",
        "timing",
        "internal_hom",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int SchedulePhotonTransmissionsOnebyOneDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_index")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_address")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "num_sent")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "number_of_qubits_to_send")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "trial")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "interval")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "timing")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "internal_hom")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "double",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SchedulePhotonTransmissionsOnebyOne *pp = (SchedulePhotonTransmissionsOnebyOne *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SchedulePhotonTransmissionsOnebyOne *pp = (SchedulePhotonTransmissionsOnebyOne *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SchedulePhotonTransmissionsOnebyOne *pp = (SchedulePhotonTransmissionsOnebyOne *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getQnic_index());
        case 1: return long2string(pp->getQnic_address());
        case 2: return long2string(pp->getNum_sent());
        case 3: return long2string(pp->getNumber_of_qubits_to_send());
        case 4: return long2string(pp->getTrial());
        case 5: return double2string(pp->getInterval());
        case 6: return simtime2string(pp->getTiming());
        case 7: return long2string(pp->getInternal_hom());
        default: return "";
    }
}

bool SchedulePhotonTransmissionsOnebyOneDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SchedulePhotonTransmissionsOnebyOne *pp = (SchedulePhotonTransmissionsOnebyOne *)object; (void)pp;
    switch (field) {
        case 0: pp->setQnic_index(string2long(value)); return true;
        case 1: pp->setQnic_address(string2long(value)); return true;
        case 2: pp->setNum_sent(string2long(value)); return true;
        case 3: pp->setNumber_of_qubits_to_send(string2long(value)); return true;
        case 4: pp->setTrial(string2long(value)); return true;
        case 5: pp->setInterval(string2double(value)); return true;
        case 6: pp->setTiming(string2simtime(value)); return true;
        case 7: pp->setInternal_hom(string2long(value)); return true;
        default: return false;
    }
}

const char *SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *SchedulePhotonTransmissionsOnebyOneDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SchedulePhotonTransmissionsOnebyOne *pp = (SchedulePhotonTransmissionsOnebyOne *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BSAresult)

BSAresult::BSAresult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->entangled = false;
}

BSAresult::BSAresult(const BSAresult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

BSAresult::~BSAresult()
{
}

BSAresult& BSAresult::operator=(const BSAresult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void BSAresult::copy(const BSAresult& other)
{
    this->entangled = other.entangled;
}

void BSAresult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->entangled);
}

void BSAresult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->entangled);
}

bool BSAresult::getEntangled() const
{
    return this->entangled;
}

void BSAresult::setEntangled(bool entangled)
{
    this->entangled = entangled;
}

class BSAresultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BSAresultDescriptor();
    virtual ~BSAresultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(BSAresultDescriptor)

BSAresultDescriptor::BSAresultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::BSAresult", "quisp::messages::header")
{
    propertynames = nullptr;
}

BSAresultDescriptor::~BSAresultDescriptor()
{
    delete[] propertynames;
}

bool BSAresultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BSAresult *>(obj)!=nullptr;
}

const char **BSAresultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BSAresultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BSAresultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BSAresultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BSAresultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "entangled",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BSAresultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "entangled")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BSAresultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **BSAresultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BSAresultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BSAresultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BSAresult *pp = (BSAresult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BSAresultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAresult *pp = (BSAresult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BSAresultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAresult *pp = (BSAresult *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEntangled());
        default: return "";
    }
}

bool BSAresultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BSAresult *pp = (BSAresult *)object; (void)pp;
    switch (field) {
        case 0: pp->setEntangled(string2bool(value)); return true;
        default: return false;
    }
}

const char *BSAresultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *BSAresultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BSAresult *pp = (BSAresult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BSAfinish)

BSAfinish::BSAfinish(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->entangled = false;
}

BSAfinish::BSAfinish(const BSAfinish& other) : ::quisp::messages::header(other)
{
    copy(other);
}

BSAfinish::~BSAfinish()
{
}

BSAfinish& BSAfinish::operator=(const BSAfinish& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void BSAfinish::copy(const BSAfinish& other)
{
    this->entangled = other.entangled;
}

void BSAfinish::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->entangled);
}

void BSAfinish::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->entangled);
}

bool BSAfinish::getEntangled() const
{
    return this->entangled;
}

void BSAfinish::setEntangled(bool entangled)
{
    this->entangled = entangled;
}

class BSAfinishDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BSAfinishDescriptor();
    virtual ~BSAfinishDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(BSAfinishDescriptor)

BSAfinishDescriptor::BSAfinishDescriptor() : omnetpp::cClassDescriptor("quisp::messages::BSAfinish", "quisp::messages::header")
{
    propertynames = nullptr;
}

BSAfinishDescriptor::~BSAfinishDescriptor()
{
    delete[] propertynames;
}

bool BSAfinishDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BSAfinish *>(obj)!=nullptr;
}

const char **BSAfinishDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BSAfinishDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BSAfinishDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BSAfinishDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BSAfinishDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "entangled",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BSAfinishDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "entangled")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BSAfinishDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **BSAfinishDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BSAfinishDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BSAfinishDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BSAfinish *pp = (BSAfinish *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BSAfinishDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAfinish *pp = (BSAfinish *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BSAfinishDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BSAfinish *pp = (BSAfinish *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEntangled());
        default: return "";
    }
}

bool BSAfinishDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BSAfinish *pp = (BSAfinish *)object; (void)pp;
    switch (field) {
        case 0: pp->setEntangled(string2bool(value)); return true;
        default: return false;
    }
}

const char *BSAfinishDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *BSAfinishDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BSAfinish *pp = (BSAfinish *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CombinedBSAresults)

CombinedBSAresults::CombinedBSAresults(const char *name, short kind) : ::quisp::messages::BSMtimingNotifier(name,kind)
{
    list_of_failed_arraysize = 0;
    this->list_of_failed = 0;
}

CombinedBSAresults::CombinedBSAresults(const CombinedBSAresults& other) : ::quisp::messages::BSMtimingNotifier(other)
{
    list_of_failed_arraysize = 0;
    this->list_of_failed = 0;
    copy(other);
}

CombinedBSAresults::~CombinedBSAresults()
{
    delete [] this->list_of_failed;
}

CombinedBSAresults& CombinedBSAresults::operator=(const CombinedBSAresults& other)
{
    if (this==&other) return *this;
    ::quisp::messages::BSMtimingNotifier::operator=(other);
    copy(other);
    return *this;
}

void CombinedBSAresults::copy(const CombinedBSAresults& other)
{
    delete [] this->list_of_failed;
    this->list_of_failed = (other.list_of_failed_arraysize==0) ? nullptr : new bool[other.list_of_failed_arraysize];
    list_of_failed_arraysize = other.list_of_failed_arraysize;
    for (unsigned int i=0; i<list_of_failed_arraysize; i++)
        this->list_of_failed[i] = other.list_of_failed[i];
}

void CombinedBSAresults::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::BSMtimingNotifier::parsimPack(b);
    b->pack(list_of_failed_arraysize);
    doParsimArrayPacking(b,this->list_of_failed,list_of_failed_arraysize);
}

void CombinedBSAresults::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::BSMtimingNotifier::parsimUnpack(b);
    delete [] this->list_of_failed;
    b->unpack(list_of_failed_arraysize);
    if (list_of_failed_arraysize==0) {
        this->list_of_failed = 0;
    } else {
        this->list_of_failed = new bool[list_of_failed_arraysize];
        doParsimArrayUnpacking(b,this->list_of_failed,list_of_failed_arraysize);
    }
}

void CombinedBSAresults::setList_of_failedArraySize(unsigned int size)
{
    bool *list_of_failed2 = (size==0) ? nullptr : new bool[size];
    unsigned int sz = list_of_failed_arraysize < size ? list_of_failed_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        list_of_failed2[i] = this->list_of_failed[i];
    for (unsigned int i=sz; i<size; i++)
        list_of_failed2[i] = 0;
    list_of_failed_arraysize = size;
    delete [] this->list_of_failed;
    this->list_of_failed = list_of_failed2;
}

unsigned int CombinedBSAresults::getList_of_failedArraySize() const
{
    return list_of_failed_arraysize;
}

bool CombinedBSAresults::getList_of_failed(unsigned int k) const
{
    if (k>=list_of_failed_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", list_of_failed_arraysize, k);
    return this->list_of_failed[k];
}

void CombinedBSAresults::setList_of_failed(unsigned int k, bool list_of_failed)
{
    if (k>=list_of_failed_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", list_of_failed_arraysize, k);
    this->list_of_failed[k] = list_of_failed;
}

class CombinedBSAresultsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CombinedBSAresultsDescriptor();
    virtual ~CombinedBSAresultsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CombinedBSAresultsDescriptor)

CombinedBSAresultsDescriptor::CombinedBSAresultsDescriptor() : omnetpp::cClassDescriptor("quisp::messages::CombinedBSAresults", "quisp::messages::BSMtimingNotifier")
{
    propertynames = nullptr;
}

CombinedBSAresultsDescriptor::~CombinedBSAresultsDescriptor()
{
    delete[] propertynames;
}

bool CombinedBSAresultsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CombinedBSAresults *>(obj)!=nullptr;
}

const char **CombinedBSAresultsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CombinedBSAresultsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CombinedBSAresultsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CombinedBSAresultsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CombinedBSAresultsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "list_of_failed",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CombinedBSAresultsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "list_of_failed")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CombinedBSAresultsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CombinedBSAresultsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CombinedBSAresultsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CombinedBSAresultsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults *pp = (CombinedBSAresults *)object; (void)pp;
    switch (field) {
        case 0: return pp->getList_of_failedArraySize();
        default: return 0;
    }
}

const char *CombinedBSAresultsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults *pp = (CombinedBSAresults *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CombinedBSAresultsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults *pp = (CombinedBSAresults *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getList_of_failed(i));
        default: return "";
    }
}

bool CombinedBSAresultsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults *pp = (CombinedBSAresults *)object; (void)pp;
    switch (field) {
        case 0: pp->setList_of_failed(i,string2bool(value)); return true;
        default: return false;
    }
}

const char *CombinedBSAresultsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CombinedBSAresultsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults *pp = (CombinedBSAresults *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CombinedBSAresults_epps)

CombinedBSAresults_epps::CombinedBSAresults_epps(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    list_of_failed_arraysize = 0;
    this->list_of_failed = 0;
}

CombinedBSAresults_epps::CombinedBSAresults_epps(const CombinedBSAresults_epps& other) : ::quisp::messages::header(other)
{
    list_of_failed_arraysize = 0;
    this->list_of_failed = 0;
    copy(other);
}

CombinedBSAresults_epps::~CombinedBSAresults_epps()
{
    delete [] this->list_of_failed;
}

CombinedBSAresults_epps& CombinedBSAresults_epps::operator=(const CombinedBSAresults_epps& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void CombinedBSAresults_epps::copy(const CombinedBSAresults_epps& other)
{
    delete [] this->list_of_failed;
    this->list_of_failed = (other.list_of_failed_arraysize==0) ? nullptr : new bool[other.list_of_failed_arraysize];
    list_of_failed_arraysize = other.list_of_failed_arraysize;
    for (unsigned int i=0; i<list_of_failed_arraysize; i++)
        this->list_of_failed[i] = other.list_of_failed[i];
}

void CombinedBSAresults_epps::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    b->pack(list_of_failed_arraysize);
    doParsimArrayPacking(b,this->list_of_failed,list_of_failed_arraysize);
}

void CombinedBSAresults_epps::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    delete [] this->list_of_failed;
    b->unpack(list_of_failed_arraysize);
    if (list_of_failed_arraysize==0) {
        this->list_of_failed = 0;
    } else {
        this->list_of_failed = new bool[list_of_failed_arraysize];
        doParsimArrayUnpacking(b,this->list_of_failed,list_of_failed_arraysize);
    }
}

void CombinedBSAresults_epps::setList_of_failedArraySize(unsigned int size)
{
    bool *list_of_failed2 = (size==0) ? nullptr : new bool[size];
    unsigned int sz = list_of_failed_arraysize < size ? list_of_failed_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        list_of_failed2[i] = this->list_of_failed[i];
    for (unsigned int i=sz; i<size; i++)
        list_of_failed2[i] = 0;
    list_of_failed_arraysize = size;
    delete [] this->list_of_failed;
    this->list_of_failed = list_of_failed2;
}

unsigned int CombinedBSAresults_epps::getList_of_failedArraySize() const
{
    return list_of_failed_arraysize;
}

bool CombinedBSAresults_epps::getList_of_failed(unsigned int k) const
{
    if (k>=list_of_failed_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", list_of_failed_arraysize, k);
    return this->list_of_failed[k];
}

void CombinedBSAresults_epps::setList_of_failed(unsigned int k, bool list_of_failed)
{
    if (k>=list_of_failed_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", list_of_failed_arraysize, k);
    this->list_of_failed[k] = list_of_failed;
}

class CombinedBSAresults_eppsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CombinedBSAresults_eppsDescriptor();
    virtual ~CombinedBSAresults_eppsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CombinedBSAresults_eppsDescriptor)

CombinedBSAresults_eppsDescriptor::CombinedBSAresults_eppsDescriptor() : omnetpp::cClassDescriptor("quisp::messages::CombinedBSAresults_epps", "quisp::messages::header")
{
    propertynames = nullptr;
}

CombinedBSAresults_eppsDescriptor::~CombinedBSAresults_eppsDescriptor()
{
    delete[] propertynames;
}

bool CombinedBSAresults_eppsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CombinedBSAresults_epps *>(obj)!=nullptr;
}

const char **CombinedBSAresults_eppsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CombinedBSAresults_eppsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CombinedBSAresults_eppsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CombinedBSAresults_eppsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CombinedBSAresults_eppsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "list_of_failed",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CombinedBSAresults_eppsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "list_of_failed")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CombinedBSAresults_eppsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CombinedBSAresults_eppsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CombinedBSAresults_eppsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CombinedBSAresults_eppsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults_epps *pp = (CombinedBSAresults_epps *)object; (void)pp;
    switch (field) {
        case 0: return pp->getList_of_failedArraySize();
        default: return 0;
    }
}

const char *CombinedBSAresults_eppsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults_epps *pp = (CombinedBSAresults_epps *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CombinedBSAresults_eppsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults_epps *pp = (CombinedBSAresults_epps *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getList_of_failed(i));
        default: return "";
    }
}

bool CombinedBSAresults_eppsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults_epps *pp = (CombinedBSAresults_epps *)object; (void)pp;
    switch (field) {
        case 0: pp->setList_of_failed(i,string2bool(value)); return true;
        default: return false;
    }
}

const char *CombinedBSAresults_eppsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CombinedBSAresults_eppsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CombinedBSAresults_epps *pp = (CombinedBSAresults_epps *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Error)

Error::Error(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
}

Error::Error(const Error& other) : ::quisp::messages::header(other)
{
    copy(other);
}

Error::~Error()
{
}

Error& Error::operator=(const Error& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void Error::copy(const Error& other)
{
    this->error_text = other.error_text;
}

void Error::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->error_text);
}

void Error::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->error_text);
}

const char * Error::getError_text() const
{
    return this->error_text.c_str();
}

void Error::setError_text(const char * error_text)
{
    this->error_text = error_text;
}

class ErrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ErrorDescriptor();
    virtual ~ErrorDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ErrorDescriptor)

ErrorDescriptor::ErrorDescriptor() : omnetpp::cClassDescriptor("quisp::messages::Error", "quisp::messages::header")
{
    propertynames = nullptr;
}

ErrorDescriptor::~ErrorDescriptor()
{
    delete[] propertynames;
}

bool ErrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Error *>(obj)!=nullptr;
}

const char **ErrorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ErrorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ErrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ErrorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ErrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "error_text",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int ErrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "error_text")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ErrorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **ErrorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ErrorDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ErrorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Error *pp = (Error *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ErrorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Error *pp = (Error *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ErrorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Error *pp = (Error *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getError_text());
        default: return "";
    }
}

bool ErrorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Error *pp = (Error *)object; (void)pp;
    switch (field) {
        case 0: pp->setError_text((value)); return true;
        default: return false;
    }
}

const char *ErrorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ErrorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Error *pp = (Error *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(StopEmitting)

StopEmitting::StopEmitting(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->qnic_address = 0;
}

StopEmitting::StopEmitting(const StopEmitting& other) : ::quisp::messages::header(other)
{
    copy(other);
}

StopEmitting::~StopEmitting()
{
}

StopEmitting& StopEmitting::operator=(const StopEmitting& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void StopEmitting::copy(const StopEmitting& other)
{
    this->qnic_address = other.qnic_address;
}

void StopEmitting::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->qnic_address);
}

void StopEmitting::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->qnic_address);
}

int StopEmitting::getQnic_address() const
{
    return this->qnic_address;
}

void StopEmitting::setQnic_address(int qnic_address)
{
    this->qnic_address = qnic_address;
}

class StopEmittingDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    StopEmittingDescriptor();
    virtual ~StopEmittingDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(StopEmittingDescriptor)

StopEmittingDescriptor::StopEmittingDescriptor() : omnetpp::cClassDescriptor("quisp::messages::StopEmitting", "quisp::messages::header")
{
    propertynames = nullptr;
}

StopEmittingDescriptor::~StopEmittingDescriptor()
{
    delete[] propertynames;
}

bool StopEmittingDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StopEmitting *>(obj)!=nullptr;
}

const char **StopEmittingDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *StopEmittingDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int StopEmittingDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int StopEmittingDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *StopEmittingDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "qnic_address",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int StopEmittingDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qnic_address")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *StopEmittingDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **StopEmittingDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *StopEmittingDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int StopEmittingDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    StopEmitting *pp = (StopEmitting *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *StopEmittingDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    StopEmitting *pp = (StopEmitting *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StopEmittingDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    StopEmitting *pp = (StopEmitting *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getQnic_address());
        default: return "";
    }
}

bool StopEmittingDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    StopEmitting *pp = (StopEmitting *)object; (void)pp;
    switch (field) {
        case 0: pp->setQnic_address(string2long(value)); return true;
        default: return false;
    }
}

const char *StopEmittingDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *StopEmittingDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    StopEmitting *pp = (StopEmitting *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SwappingResult)

SwappingResult::SwappingResult(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->RuleSet_id = 0;
    this->Rule_id = 0;
    this->action_index = 0;
    this->left_Dest = 0;
    this->right_Dest = 0;
    this->new_partner_left = 0;
    this->new_partner_qnic_index_left = 0;
    this->new_partner_qnic_address_left = 0;
    this->measured_qubit_index_left = 0;
    this->new_partner_right = 0;
    this->new_partner_qnic_index_right = 0;
    this->new_partner_qnic_address_right = 0;
    this->measured_qubit_index_right = 0;
    this->operation_type_left = 0;
    this->operation_type_right = 0;
    this->operation_type = 0;
    this->new_partner = 0;
    this->new_partner_qnic_index = 0;
    this->new_partner_qnic_address = 0;
    this->measured_qubit_index = 0;
}

SwappingResult::SwappingResult(const SwappingResult& other) : ::quisp::messages::header(other)
{
    copy(other);
}

SwappingResult::~SwappingResult()
{
}

SwappingResult& SwappingResult::operator=(const SwappingResult& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void SwappingResult::copy(const SwappingResult& other)
{
    this->RuleSet_id = other.RuleSet_id;
    this->Rule_id = other.Rule_id;
    this->action_index = other.action_index;
    this->left_Dest = other.left_Dest;
    this->right_Dest = other.right_Dest;
    this->new_partner_left = other.new_partner_left;
    this->new_partner_qnic_index_left = other.new_partner_qnic_index_left;
    this->new_partner_qnic_address_left = other.new_partner_qnic_address_left;
    this->measured_qubit_index_left = other.measured_qubit_index_left;
    this->new_partner_qnic_type_left = other.new_partner_qnic_type_left;
    this->new_partner_right = other.new_partner_right;
    this->new_partner_qnic_index_right = other.new_partner_qnic_index_right;
    this->new_partner_qnic_address_right = other.new_partner_qnic_address_right;
    this->measured_qubit_index_right = other.measured_qubit_index_right;
    this->new_partner_qnic_type_right = other.new_partner_qnic_type_right;
    this->operation_type_left = other.operation_type_left;
    this->operation_type_right = other.operation_type_right;
    this->operation_type = other.operation_type;
    this->new_partner = other.new_partner;
    this->new_partner_qnic_index = other.new_partner_qnic_index;
    this->new_partner_qnic_address = other.new_partner_qnic_address;
    this->measured_qubit_index = other.measured_qubit_index;
    this->new_partner_qnic_type = other.new_partner_qnic_type;
}

void SwappingResult::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->RuleSet_id);
    doParsimPacking(b,this->Rule_id);
    doParsimPacking(b,this->action_index);
    doParsimPacking(b,this->left_Dest);
    doParsimPacking(b,this->right_Dest);
    doParsimPacking(b,this->new_partner_left);
    doParsimPacking(b,this->new_partner_qnic_index_left);
    doParsimPacking(b,this->new_partner_qnic_address_left);
    doParsimPacking(b,this->measured_qubit_index_left);
    doParsimPacking(b,this->new_partner_qnic_type_left);
    doParsimPacking(b,this->new_partner_right);
    doParsimPacking(b,this->new_partner_qnic_index_right);
    doParsimPacking(b,this->new_partner_qnic_address_right);
    doParsimPacking(b,this->measured_qubit_index_right);
    doParsimPacking(b,this->new_partner_qnic_type_right);
    doParsimPacking(b,this->operation_type_left);
    doParsimPacking(b,this->operation_type_right);
    doParsimPacking(b,this->operation_type);
    doParsimPacking(b,this->new_partner);
    doParsimPacking(b,this->new_partner_qnic_index);
    doParsimPacking(b,this->new_partner_qnic_address);
    doParsimPacking(b,this->measured_qubit_index);
    doParsimPacking(b,this->new_partner_qnic_type);
}

void SwappingResult::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->RuleSet_id);
    doParsimUnpacking(b,this->Rule_id);
    doParsimUnpacking(b,this->action_index);
    doParsimUnpacking(b,this->left_Dest);
    doParsimUnpacking(b,this->right_Dest);
    doParsimUnpacking(b,this->new_partner_left);
    doParsimUnpacking(b,this->new_partner_qnic_index_left);
    doParsimUnpacking(b,this->new_partner_qnic_address_left);
    doParsimUnpacking(b,this->measured_qubit_index_left);
    doParsimUnpacking(b,this->new_partner_qnic_type_left);
    doParsimUnpacking(b,this->new_partner_right);
    doParsimUnpacking(b,this->new_partner_qnic_index_right);
    doParsimUnpacking(b,this->new_partner_qnic_address_right);
    doParsimUnpacking(b,this->measured_qubit_index_right);
    doParsimUnpacking(b,this->new_partner_qnic_type_right);
    doParsimUnpacking(b,this->operation_type_left);
    doParsimUnpacking(b,this->operation_type_right);
    doParsimUnpacking(b,this->operation_type);
    doParsimUnpacking(b,this->new_partner);
    doParsimUnpacking(b,this->new_partner_qnic_index);
    doParsimUnpacking(b,this->new_partner_qnic_address);
    doParsimUnpacking(b,this->measured_qubit_index);
    doParsimUnpacking(b,this->new_partner_qnic_type);
}

unsigned long SwappingResult::getRuleSet_id() const
{
    return this->RuleSet_id;
}

void SwappingResult::setRuleSet_id(unsigned long RuleSet_id)
{
    this->RuleSet_id = RuleSet_id;
}

int SwappingResult::getRule_id() const
{
    return this->Rule_id;
}

void SwappingResult::setRule_id(int Rule_id)
{
    this->Rule_id = Rule_id;
}

int SwappingResult::getAction_index() const
{
    return this->action_index;
}

void SwappingResult::setAction_index(int action_index)
{
    this->action_index = action_index;
}

int SwappingResult::getLeft_Dest() const
{
    return this->left_Dest;
}

void SwappingResult::setLeft_Dest(int left_Dest)
{
    this->left_Dest = left_Dest;
}

int SwappingResult::getRight_Dest() const
{
    return this->right_Dest;
}

void SwappingResult::setRight_Dest(int right_Dest)
{
    this->right_Dest = right_Dest;
}

int SwappingResult::getNew_partner_left() const
{
    return this->new_partner_left;
}

void SwappingResult::setNew_partner_left(int new_partner_left)
{
    this->new_partner_left = new_partner_left;
}

int SwappingResult::getNew_partner_qnic_index_left() const
{
    return this->new_partner_qnic_index_left;
}

void SwappingResult::setNew_partner_qnic_index_left(int new_partner_qnic_index_left)
{
    this->new_partner_qnic_index_left = new_partner_qnic_index_left;
}

int SwappingResult::getNew_partner_qnic_address_left() const
{
    return this->new_partner_qnic_address_left;
}

void SwappingResult::setNew_partner_qnic_address_left(int new_partner_qnic_address_left)
{
    this->new_partner_qnic_address_left = new_partner_qnic_address_left;
}

int SwappingResult::getMeasured_qubit_index_left() const
{
    return this->measured_qubit_index_left;
}

void SwappingResult::setMeasured_qubit_index_left(int measured_qubit_index_left)
{
    this->measured_qubit_index_left = measured_qubit_index_left;
}

QNIC_type& SwappingResult::getNew_partner_qnic_type_left()
{
    return this->new_partner_qnic_type_left;
}

void SwappingResult::setNew_partner_qnic_type_left(const QNIC_type& new_partner_qnic_type_left)
{
    this->new_partner_qnic_type_left = new_partner_qnic_type_left;
}

int SwappingResult::getNew_partner_right() const
{
    return this->new_partner_right;
}

void SwappingResult::setNew_partner_right(int new_partner_right)
{
    this->new_partner_right = new_partner_right;
}

int SwappingResult::getNew_partner_qnic_index_right() const
{
    return this->new_partner_qnic_index_right;
}

void SwappingResult::setNew_partner_qnic_index_right(int new_partner_qnic_index_right)
{
    this->new_partner_qnic_index_right = new_partner_qnic_index_right;
}

int SwappingResult::getNew_partner_qnic_address_right() const
{
    return this->new_partner_qnic_address_right;
}

void SwappingResult::setNew_partner_qnic_address_right(int new_partner_qnic_address_right)
{
    this->new_partner_qnic_address_right = new_partner_qnic_address_right;
}

int SwappingResult::getMeasured_qubit_index_right() const
{
    return this->measured_qubit_index_right;
}

void SwappingResult::setMeasured_qubit_index_right(int measured_qubit_index_right)
{
    this->measured_qubit_index_right = measured_qubit_index_right;
}

QNIC_type& SwappingResult::getNew_partner_qnic_type_right()
{
    return this->new_partner_qnic_type_right;
}

void SwappingResult::setNew_partner_qnic_type_right(const QNIC_type& new_partner_qnic_type_right)
{
    this->new_partner_qnic_type_right = new_partner_qnic_type_right;
}

int SwappingResult::getOperation_type_left() const
{
    return this->operation_type_left;
}

void SwappingResult::setOperation_type_left(int operation_type_left)
{
    this->operation_type_left = operation_type_left;
}

int SwappingResult::getOperation_type_right() const
{
    return this->operation_type_right;
}

void SwappingResult::setOperation_type_right(int operation_type_right)
{
    this->operation_type_right = operation_type_right;
}

int SwappingResult::getOperation_type() const
{
    return this->operation_type;
}

void SwappingResult::setOperation_type(int operation_type)
{
    this->operation_type = operation_type;
}

int SwappingResult::getNew_partner() const
{
    return this->new_partner;
}

void SwappingResult::setNew_partner(int new_partner)
{
    this->new_partner = new_partner;
}

int SwappingResult::getNew_partner_qnic_index() const
{
    return this->new_partner_qnic_index;
}

void SwappingResult::setNew_partner_qnic_index(int new_partner_qnic_index)
{
    this->new_partner_qnic_index = new_partner_qnic_index;
}

int SwappingResult::getNew_partner_qnic_address() const
{
    return this->new_partner_qnic_address;
}

void SwappingResult::setNew_partner_qnic_address(int new_partner_qnic_address)
{
    this->new_partner_qnic_address = new_partner_qnic_address;
}

int SwappingResult::getMeasured_qubit_index() const
{
    return this->measured_qubit_index;
}

void SwappingResult::setMeasured_qubit_index(int measured_qubit_index)
{
    this->measured_qubit_index = measured_qubit_index;
}

QNIC_type& SwappingResult::getNew_partner_qnic_type()
{
    return this->new_partner_qnic_type;
}

void SwappingResult::setNew_partner_qnic_type(const QNIC_type& new_partner_qnic_type)
{
    this->new_partner_qnic_type = new_partner_qnic_type;
}

class SwappingResultDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SwappingResultDescriptor();
    virtual ~SwappingResultDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(SwappingResultDescriptor)

SwappingResultDescriptor::SwappingResultDescriptor() : omnetpp::cClassDescriptor("quisp::messages::SwappingResult", "quisp::messages::header")
{
    propertynames = nullptr;
}

SwappingResultDescriptor::~SwappingResultDescriptor()
{
    delete[] propertynames;
}

bool SwappingResultDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SwappingResult *>(obj)!=nullptr;
}

const char **SwappingResultDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SwappingResultDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SwappingResultDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 23+basedesc->getFieldCount() : 23;
}

unsigned int SwappingResultDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<23) ? fieldTypeFlags[field] : 0;
}

const char *SwappingResultDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "RuleSet_id",
        "Rule_id",
        "action_index",
        "left_Dest",
        "right_Dest",
        "new_partner_left",
        "new_partner_qnic_index_left",
        "new_partner_qnic_address_left",
        "measured_qubit_index_left",
        "new_partner_qnic_type_left",
        "new_partner_right",
        "new_partner_qnic_index_right",
        "new_partner_qnic_address_right",
        "measured_qubit_index_right",
        "new_partner_qnic_type_right",
        "operation_type_left",
        "operation_type_right",
        "operation_type",
        "new_partner",
        "new_partner_qnic_index",
        "new_partner_qnic_address",
        "measured_qubit_index",
        "new_partner_qnic_type",
    };
    return (field>=0 && field<23) ? fieldNames[field] : nullptr;
}

int SwappingResultDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet_id")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "Rule_id")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "action_index")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "left_Dest")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "right_Dest")==0) return base+4;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_left")==0) return base+5;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_index_left")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_address_left")==0) return base+7;
    if (fieldName[0]=='m' && strcmp(fieldName, "measured_qubit_index_left")==0) return base+8;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_type_left")==0) return base+9;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_right")==0) return base+10;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_index_right")==0) return base+11;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_address_right")==0) return base+12;
    if (fieldName[0]=='m' && strcmp(fieldName, "measured_qubit_index_right")==0) return base+13;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_type_right")==0) return base+14;
    if (fieldName[0]=='o' && strcmp(fieldName, "operation_type_left")==0) return base+15;
    if (fieldName[0]=='o' && strcmp(fieldName, "operation_type_right")==0) return base+16;
    if (fieldName[0]=='o' && strcmp(fieldName, "operation_type")==0) return base+17;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner")==0) return base+18;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_index")==0) return base+19;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_address")==0) return base+20;
    if (fieldName[0]=='m' && strcmp(fieldName, "measured_qubit_index")==0) return base+21;
    if (fieldName[0]=='n' && strcmp(fieldName, "new_partner_qnic_type")==0) return base+22;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SwappingResultDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "QNIC_type",
        "int",
        "int",
        "int",
        "int",
        "QNIC_type",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "QNIC_type",
    };
    return (field>=0 && field<23) ? fieldTypeStrings[field] : nullptr;
}

const char **SwappingResultDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SwappingResultDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SwappingResultDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SwappingResult *pp = (SwappingResult *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SwappingResultDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SwappingResult *pp = (SwappingResult *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SwappingResultDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SwappingResult *pp = (SwappingResult *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRuleSet_id());
        case 1: return long2string(pp->getRule_id());
        case 2: return long2string(pp->getAction_index());
        case 3: return long2string(pp->getLeft_Dest());
        case 4: return long2string(pp->getRight_Dest());
        case 5: return long2string(pp->getNew_partner_left());
        case 6: return long2string(pp->getNew_partner_qnic_index_left());
        case 7: return long2string(pp->getNew_partner_qnic_address_left());
        case 8: return long2string(pp->getMeasured_qubit_index_left());
        case 9: {std::stringstream out; out << pp->getNew_partner_qnic_type_left(); return out.str();}
        case 10: return long2string(pp->getNew_partner_right());
        case 11: return long2string(pp->getNew_partner_qnic_index_right());
        case 12: return long2string(pp->getNew_partner_qnic_address_right());
        case 13: return long2string(pp->getMeasured_qubit_index_right());
        case 14: {std::stringstream out; out << pp->getNew_partner_qnic_type_right(); return out.str();}
        case 15: return long2string(pp->getOperation_type_left());
        case 16: return long2string(pp->getOperation_type_right());
        case 17: return long2string(pp->getOperation_type());
        case 18: return long2string(pp->getNew_partner());
        case 19: return long2string(pp->getNew_partner_qnic_index());
        case 20: return long2string(pp->getNew_partner_qnic_address());
        case 21: return long2string(pp->getMeasured_qubit_index());
        case 22: {std::stringstream out; out << pp->getNew_partner_qnic_type(); return out.str();}
        default: return "";
    }
}

bool SwappingResultDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SwappingResult *pp = (SwappingResult *)object; (void)pp;
    switch (field) {
        case 0: pp->setRuleSet_id(string2ulong(value)); return true;
        case 1: pp->setRule_id(string2long(value)); return true;
        case 2: pp->setAction_index(string2long(value)); return true;
        case 3: pp->setLeft_Dest(string2long(value)); return true;
        case 4: pp->setRight_Dest(string2long(value)); return true;
        case 5: pp->setNew_partner_left(string2long(value)); return true;
        case 6: pp->setNew_partner_qnic_index_left(string2long(value)); return true;
        case 7: pp->setNew_partner_qnic_address_left(string2long(value)); return true;
        case 8: pp->setMeasured_qubit_index_left(string2long(value)); return true;
        case 10: pp->setNew_partner_right(string2long(value)); return true;
        case 11: pp->setNew_partner_qnic_index_right(string2long(value)); return true;
        case 12: pp->setNew_partner_qnic_address_right(string2long(value)); return true;
        case 13: pp->setMeasured_qubit_index_right(string2long(value)); return true;
        case 15: pp->setOperation_type_left(string2long(value)); return true;
        case 16: pp->setOperation_type_right(string2long(value)); return true;
        case 17: pp->setOperation_type(string2long(value)); return true;
        case 18: pp->setNew_partner(string2long(value)); return true;
        case 19: pp->setNew_partner_qnic_index(string2long(value)); return true;
        case 20: pp->setNew_partner_qnic_address(string2long(value)); return true;
        case 21: pp->setMeasured_qubit_index(string2long(value)); return true;
        default: return false;
    }
}

const char *SwappingResultDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 9: return omnetpp::opp_typename(typeid(QNIC_type));
        case 14: return omnetpp::opp_typename(typeid(QNIC_type));
        case 22: return omnetpp::opp_typename(typeid(QNIC_type));
        default: return nullptr;
    };
}

void *SwappingResultDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SwappingResult *pp = (SwappingResult *)object; (void)pp;
    switch (field) {
        case 9: return (void *)(&pp->getNew_partner_qnic_type_left()); break;
        case 14: return (void *)(&pp->getNew_partner_qnic_type_right()); break;
        case 22: return (void *)(&pp->getNew_partner_qnic_type()); break;
        default: return nullptr;
    }
}

Register_Class(InternalRuleSetForwarding)

InternalRuleSetForwarding::InternalRuleSetForwarding(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->RuleSet_id = 0;
    this->Rule_id = 0;
}

InternalRuleSetForwarding::InternalRuleSetForwarding(const InternalRuleSetForwarding& other) : ::quisp::messages::header(other)
{
    copy(other);
}

InternalRuleSetForwarding::~InternalRuleSetForwarding()
{
}

InternalRuleSetForwarding& InternalRuleSetForwarding::operator=(const InternalRuleSetForwarding& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void InternalRuleSetForwarding::copy(const InternalRuleSetForwarding& other)
{
    this->RuleSet_id = other.RuleSet_id;
    this->Rule_id = other.Rule_id;
    this->RuleSet = other.RuleSet;
}

void InternalRuleSetForwarding::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->RuleSet_id);
    doParsimPacking(b,this->Rule_id);
    doParsimPacking(b,this->RuleSet);
}

void InternalRuleSetForwarding::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->RuleSet_id);
    doParsimUnpacking(b,this->Rule_id);
    doParsimUnpacking(b,this->RuleSet);
}

unsigned long InternalRuleSetForwarding::getRuleSet_id() const
{
    return this->RuleSet_id;
}

void InternalRuleSetForwarding::setRuleSet_id(unsigned long RuleSet_id)
{
    this->RuleSet_id = RuleSet_id;
}

int InternalRuleSetForwarding::getRule_id() const
{
    return this->Rule_id;
}

void InternalRuleSetForwarding::setRule_id(int Rule_id)
{
    this->Rule_id = Rule_id;
}

RuleSetField& InternalRuleSetForwarding::getRuleSet()
{
    return this->RuleSet;
}

void InternalRuleSetForwarding::setRuleSet(const RuleSetField& RuleSet)
{
    this->RuleSet = RuleSet;
}

class InternalRuleSetForwardingDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    InternalRuleSetForwardingDescriptor();
    virtual ~InternalRuleSetForwardingDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(InternalRuleSetForwardingDescriptor)

InternalRuleSetForwardingDescriptor::InternalRuleSetForwardingDescriptor() : omnetpp::cClassDescriptor("quisp::messages::InternalRuleSetForwarding", "quisp::messages::header")
{
    propertynames = nullptr;
}

InternalRuleSetForwardingDescriptor::~InternalRuleSetForwardingDescriptor()
{
    delete[] propertynames;
}

bool InternalRuleSetForwardingDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<InternalRuleSetForwarding *>(obj)!=nullptr;
}

const char **InternalRuleSetForwardingDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *InternalRuleSetForwardingDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int InternalRuleSetForwardingDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int InternalRuleSetForwardingDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *InternalRuleSetForwardingDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "RuleSet_id",
        "Rule_id",
        "RuleSet",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int InternalRuleSetForwardingDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet_id")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "Rule_id")==0) return base+1;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *InternalRuleSetForwardingDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
        "int",
        "RuleSetField",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **InternalRuleSetForwardingDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *InternalRuleSetForwardingDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int InternalRuleSetForwardingDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding *pp = (InternalRuleSetForwarding *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *InternalRuleSetForwardingDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding *pp = (InternalRuleSetForwarding *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string InternalRuleSetForwardingDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding *pp = (InternalRuleSetForwarding *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRuleSet_id());
        case 1: return long2string(pp->getRule_id());
        case 2: {std::stringstream out; out << pp->getRuleSet(); return out.str();}
        default: return "";
    }
}

bool InternalRuleSetForwardingDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding *pp = (InternalRuleSetForwarding *)object; (void)pp;
    switch (field) {
        case 0: pp->setRuleSet_id(string2ulong(value)); return true;
        case 1: pp->setRule_id(string2long(value)); return true;
        default: return false;
    }
}

const char *InternalRuleSetForwardingDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(RuleSetField));
        default: return nullptr;
    };
}

void *InternalRuleSetForwardingDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding *pp = (InternalRuleSetForwarding *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getRuleSet()); break;
        default: return nullptr;
    }
}

Register_Class(InternalRuleSetForwarding_Application)

InternalRuleSetForwarding_Application::InternalRuleSetForwarding_Application(const char *name, short kind) : ::quisp::messages::header(name,kind)
{
    this->RuleSet_id = 0;
    this->Rule_id = 0;
    this->application_type = 0;
}

InternalRuleSetForwarding_Application::InternalRuleSetForwarding_Application(const InternalRuleSetForwarding_Application& other) : ::quisp::messages::header(other)
{
    copy(other);
}

InternalRuleSetForwarding_Application::~InternalRuleSetForwarding_Application()
{
}

InternalRuleSetForwarding_Application& InternalRuleSetForwarding_Application::operator=(const InternalRuleSetForwarding_Application& other)
{
    if (this==&other) return *this;
    ::quisp::messages::header::operator=(other);
    copy(other);
    return *this;
}

void InternalRuleSetForwarding_Application::copy(const InternalRuleSetForwarding_Application& other)
{
    this->RuleSet_id = other.RuleSet_id;
    this->Rule_id = other.Rule_id;
    this->application_type = other.application_type;
    this->RuleSet = other.RuleSet;
}

void InternalRuleSetForwarding_Application::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::quisp::messages::header::parsimPack(b);
    doParsimPacking(b,this->RuleSet_id);
    doParsimPacking(b,this->Rule_id);
    doParsimPacking(b,this->application_type);
    doParsimPacking(b,this->RuleSet);
}

void InternalRuleSetForwarding_Application::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::quisp::messages::header::parsimUnpack(b);
    doParsimUnpacking(b,this->RuleSet_id);
    doParsimUnpacking(b,this->Rule_id);
    doParsimUnpacking(b,this->application_type);
    doParsimUnpacking(b,this->RuleSet);
}

unsigned long InternalRuleSetForwarding_Application::getRuleSet_id() const
{
    return this->RuleSet_id;
}

void InternalRuleSetForwarding_Application::setRuleSet_id(unsigned long RuleSet_id)
{
    this->RuleSet_id = RuleSet_id;
}

int InternalRuleSetForwarding_Application::getRule_id() const
{
    return this->Rule_id;
}

void InternalRuleSetForwarding_Application::setRule_id(int Rule_id)
{
    this->Rule_id = Rule_id;
}

int InternalRuleSetForwarding_Application::getApplication_type() const
{
    return this->application_type;
}

void InternalRuleSetForwarding_Application::setApplication_type(int application_type)
{
    this->application_type = application_type;
}

RuleSetField& InternalRuleSetForwarding_Application::getRuleSet()
{
    return this->RuleSet;
}

void InternalRuleSetForwarding_Application::setRuleSet(const RuleSetField& RuleSet)
{
    this->RuleSet = RuleSet;
}

class InternalRuleSetForwarding_ApplicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    InternalRuleSetForwarding_ApplicationDescriptor();
    virtual ~InternalRuleSetForwarding_ApplicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(InternalRuleSetForwarding_ApplicationDescriptor)

InternalRuleSetForwarding_ApplicationDescriptor::InternalRuleSetForwarding_ApplicationDescriptor() : omnetpp::cClassDescriptor("quisp::messages::InternalRuleSetForwarding_Application", "quisp::messages::header")
{
    propertynames = nullptr;
}

InternalRuleSetForwarding_ApplicationDescriptor::~InternalRuleSetForwarding_ApplicationDescriptor()
{
    delete[] propertynames;
}

bool InternalRuleSetForwarding_ApplicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<InternalRuleSetForwarding_Application *>(obj)!=nullptr;
}

const char **InternalRuleSetForwarding_ApplicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *InternalRuleSetForwarding_ApplicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int InternalRuleSetForwarding_ApplicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int InternalRuleSetForwarding_ApplicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *InternalRuleSetForwarding_ApplicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "RuleSet_id",
        "Rule_id",
        "application_type",
        "RuleSet",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int InternalRuleSetForwarding_ApplicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet_id")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "Rule_id")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "application_type")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "RuleSet")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *InternalRuleSetForwarding_ApplicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
        "int",
        "int",
        "RuleSetField",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **InternalRuleSetForwarding_ApplicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *InternalRuleSetForwarding_ApplicationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int InternalRuleSetForwarding_ApplicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding_Application *pp = (InternalRuleSetForwarding_Application *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *InternalRuleSetForwarding_ApplicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding_Application *pp = (InternalRuleSetForwarding_Application *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string InternalRuleSetForwarding_ApplicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding_Application *pp = (InternalRuleSetForwarding_Application *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRuleSet_id());
        case 1: return long2string(pp->getRule_id());
        case 2: return long2string(pp->getApplication_type());
        case 3: {std::stringstream out; out << pp->getRuleSet(); return out.str();}
        default: return "";
    }
}

bool InternalRuleSetForwarding_ApplicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding_Application *pp = (InternalRuleSetForwarding_Application *)object; (void)pp;
    switch (field) {
        case 0: pp->setRuleSet_id(string2ulong(value)); return true;
        case 1: pp->setRule_id(string2long(value)); return true;
        case 2: pp->setApplication_type(string2long(value)); return true;
        default: return false;
    }
}

const char *InternalRuleSetForwarding_ApplicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(RuleSetField));
        default: return nullptr;
    };
}

void *InternalRuleSetForwarding_ApplicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    InternalRuleSetForwarding_Application *pp = (InternalRuleSetForwarding_Application *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getRuleSet()); break;
        default: return nullptr;
    }
}

} // namespace messages
} // namespace quisp

