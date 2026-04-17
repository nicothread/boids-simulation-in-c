#ifndef BOIDS_CONSTS_H
#define BOIDS_CONSTS_H

/* ── Simulation parameters ─────────────────────────────────────────── */
#define WINDOW_W      1024
#define WINDOW_H      1024
#define NUM_BOIDS     512

#define MAX_SPEED     3.5f
#define MAX_FORCE     0.08f

#define VIEW_RADIUS   80.0f   /* neighborhood radius                   */
#define SEP_RADIUS    25.0f   /* personal-space radius                 */

#define W_SEP         1.6f    /* weight: separation                    */
#define W_ALI         1.0f    /* weight: alignment                     */
#define W_COH         1.0f    /* weight: cohesion                      */

#define TARGET_FPS    60
#define FRAME_MS      (1000 / TARGET_FPS)

#endif // BOIDS_CONSTS_H
