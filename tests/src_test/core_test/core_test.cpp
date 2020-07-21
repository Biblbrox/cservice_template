#include "core_test.h"
#include "core.h"
#include "pack.h"

//=======================================================================================
/*! \test TEST( CoreTest, test_constructor )
 * \brief Core default constructor with run.
 * \details Transmit default pack after run and get number of operations.
 */
TEST( CoreTest, test_constructor )
{
    Core core;
    Pack pack;

    int count {0};
    core.processed.link( [&]( const int64_t ts, const ZcmService& msg ){ ++count; } );

    core.run( pack );

    ASSERT_EQ( 1, count );
}
//=======================================================================================
