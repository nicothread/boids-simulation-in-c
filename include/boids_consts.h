#ifndef BOIDS_CONSTS_H
#define BOIDS_CONSTS_H

#define MAX_SPEED     3.5f
#define MAX_FORCE     0.08f
#define MAX_DETECTION 30

#define VIEW_RADIUS   80.0f   /* neighborhood radius                   */
#define SEP_RADIUS    25.0f   /* personal-space radius                 */

#define W_SEP         1.6f    /* weight: separation                    */
#define W_ALI         1.0f    /* weight: alignment                     */
#define W_COH         1.0f    /* weight: cohesion                      */

#endif // BOIDS_CONSTS_H
