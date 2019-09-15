#include "divider.h"

void divide(divider_s *answer, unsigned number, unsigned divide_by) {

    if (NULL != answer) {

        if (0 != divide_by) {

            answer->quotient  = number/divide_by;
            answer->remainder = number%divide_by;

        } else {

            /* undefined divide_by 0 */
        }
    }
}
