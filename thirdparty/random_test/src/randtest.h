
/*  Random test function prototypes  */

#ifdef __cplusplus
extern "C" {
#endif

extern void rt_init(int binmode);
extern void rt_add(void *buf, int bufl);
extern void rt_end(double *r_ent, double *r_chisq, double *r_mean,
                   double *r_montepicalc, double *r_scc);

#ifdef __cplusplus
}
#endif