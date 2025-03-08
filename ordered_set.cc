#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
