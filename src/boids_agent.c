#include "boids_agent.h"
#include "boids_agent_helper.h"

static Vec2 separation(Boid *boids, int idx){
    Vec2  steer = {0,0};
    int   count = 0;
    Boid *me = &boids[idx];

    for(int i = 0; i < NUM_BOIDS; i++){
        if(i == idx) continue;
        Vec2 diff = v2sub(me->pos, boids[i].pos);
        float d   = v2len(diff);
        if(d > 0 && d < SEP_RADIUS){
            steer = v2add(steer, v2scale(v2norm(diff), 1.0f/d));
            count++;
        }
    }
    if(count == 0) return steer;
    steer = v2scale(steer, 1.0f/count);
    return steer_toward(steer, me->vel);
}

static Vec2 alignment(Boid *boids, int idx){
    Vec2 avg_vel = {0,0};
    int  count   = 0;
    Boid *me = &boids[idx];

    for(int i = 0; i < NUM_BOIDS; i++){
        if(i == idx) continue;
        float d = v2len(v2sub(me->pos, boids[i].pos));
        if(d < VIEW_RADIUS){
            avg_vel = v2add(avg_vel, boids[i].vel);
            count++;
        }
    }
    if(count == 0) return avg_vel;
    avg_vel = v2scale(avg_vel, 1.0f/count);
    return steer_toward(avg_vel, me->vel);
}

static Vec2 cohesion(Boid *boids, int idx){
    Vec2 center = {0,0};
    int  count  = 0;
    Boid *me = &boids[idx];

    for(int i = 0; i < NUM_BOIDS; i++){
        if(i == idx) continue;
        float d = v2len(v2sub(me->pos, boids[i].pos));
        if(d < VIEW_RADIUS){
            center = v2add(center, boids[i].pos);
            count++;
        }
    }
    if(count == 0) return (Vec2){0,0};
    center = v2scale(center, 1.0f/count);
    Vec2 desired = v2sub(center, me->pos);
    return steer_toward(desired, me->vel);
}

void boid_init(Boid *b){
    b->pos = (Vec2){ randf(0, WINDOW_W), randf(0, WINDOW_H) };
    float angle = randf(0, 2.0f * (float)M_PI);
    float speed = randf(1.5f, MAX_SPEED);
    b->vel = (Vec2){ cosf(angle)*speed, sinf(angle)*speed };
    b->speed = v2len(b->vel) / MAX_SPEED;
    b->acc = (Vec2){0,0};
}

void boid_update(Boid *boids, int idx){
    Boid *b = &boids[idx];

    Vec2 sep = v2scale(separation(boids, idx), W_SEP);
    Vec2 ali = v2scale(alignment(boids, idx), W_ALI);
    Vec2 coh = v2scale(cohesion(boids, idx), W_COH);

    b->acc = v2add(b->acc, sep);
    b->acc = v2add(b->acc, ali);
    b->acc = v2add(b->acc, coh);

    b->vel = v2limit(v2add(b->vel, b->acc), MAX_SPEED);
    b->speed = v2len(b->vel) / MAX_SPEED;
    b->pos = v2add(b->pos, b->vel);
    b->acc = (Vec2){0,0};   /* reset each frame */
}