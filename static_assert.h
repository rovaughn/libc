
#define STATIC_ASSERT(MSG,CND) \
    typedef char static_assertion_##MSG[(CND)?1:-1];

