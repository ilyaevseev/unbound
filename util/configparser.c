/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 39 "./util/configparser.y"
#include "config.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "util/configyyrename.h"
#include "util/config_file.h"
#include "util/net_help.h"

int ub_c_lex(void);
void ub_c_error(const char *message);

static void validate_respip_action(const char* action);

/* these need to be global, otherwise they cannot be used inside yacc */
extern struct config_parser_state* cfg_parser;

#if 0
#define OUTYY(s)  printf s /* used ONLY when debugging */
#else
#define OUTYY(s)
#endif

#line 66 "./util/configparser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char*	str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 59 "util/configparser.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SPACE 257
#define LETTER 258
#define NEWLINE 259
#define COMMENT 260
#define COLON 261
#define ANY 262
#define ZONESTR 263
#define STRING_ARG 264
#define VAR_SERVER 265
#define VAR_VERBOSITY 266
#define VAR_NUM_THREADS 267
#define VAR_PORT 268
#define VAR_OUTGOING_RANGE 269
#define VAR_INTERFACE 270
#define VAR_DO_IP4 271
#define VAR_DO_IP6 272
#define VAR_PREFER_IP6 273
#define VAR_DO_UDP 274
#define VAR_DO_TCP 275
#define VAR_TCP_MSS 276
#define VAR_OUTGOING_TCP_MSS 277
#define VAR_CHROOT 278
#define VAR_USERNAME 279
#define VAR_DIRECTORY 280
#define VAR_LOGFILE 281
#define VAR_PIDFILE 282
#define VAR_MSG_CACHE_SIZE 283
#define VAR_MSG_CACHE_SLABS 284
#define VAR_NUM_QUERIES_PER_THREAD 285
#define VAR_RRSET_CACHE_SIZE 286
#define VAR_RRSET_CACHE_SLABS 287
#define VAR_OUTGOING_NUM_TCP 288
#define VAR_INFRA_HOST_TTL 289
#define VAR_INFRA_LAME_TTL 290
#define VAR_INFRA_CACHE_SLABS 291
#define VAR_INFRA_CACHE_NUMHOSTS 292
#define VAR_INFRA_CACHE_LAME_SIZE 293
#define VAR_NAME 294
#define VAR_STUB_ZONE 295
#define VAR_STUB_HOST 296
#define VAR_STUB_ADDR 297
#define VAR_TARGET_FETCH_POLICY 298
#define VAR_HARDEN_SHORT_BUFSIZE 299
#define VAR_HARDEN_LARGE_QUERIES 300
#define VAR_FORWARD_ZONE 301
#define VAR_FORWARD_HOST 302
#define VAR_FORWARD_ADDR 303
#define VAR_DO_NOT_QUERY_ADDRESS 304
#define VAR_HIDE_IDENTITY 305
#define VAR_HIDE_VERSION 306
#define VAR_IDENTITY 307
#define VAR_VERSION 308
#define VAR_HARDEN_GLUE 309
#define VAR_MODULE_CONF 310
#define VAR_TRUST_ANCHOR_FILE 311
#define VAR_TRUST_ANCHOR 312
#define VAR_VAL_OVERRIDE_DATE 313
#define VAR_BOGUS_TTL 314
#define VAR_VAL_CLEAN_ADDITIONAL 315
#define VAR_VAL_PERMISSIVE_MODE 316
#define VAR_INCOMING_NUM_TCP 317
#define VAR_MSG_BUFFER_SIZE 318
#define VAR_KEY_CACHE_SIZE 319
#define VAR_KEY_CACHE_SLABS 320
#define VAR_TRUSTED_KEYS_FILE 321
#define VAR_VAL_NSEC3_KEYSIZE_ITERATIONS 322
#define VAR_USE_SYSLOG 323
#define VAR_OUTGOING_INTERFACE 324
#define VAR_ROOT_HINTS 325
#define VAR_DO_NOT_QUERY_LOCALHOST 326
#define VAR_CACHE_MAX_TTL 327
#define VAR_HARDEN_DNSSEC_STRIPPED 328
#define VAR_ACCESS_CONTROL 329
#define VAR_LOCAL_ZONE 330
#define VAR_LOCAL_DATA 331
#define VAR_INTERFACE_AUTOMATIC 332
#define VAR_STATISTICS_INTERVAL 333
#define VAR_DO_DAEMONIZE 334
#define VAR_USE_CAPS_FOR_ID 335
#define VAR_STATISTICS_CUMULATIVE 336
#define VAR_OUTGOING_PORT_PERMIT 337
#define VAR_OUTGOING_PORT_AVOID 338
#define VAR_DLV_ANCHOR_FILE 339
#define VAR_DLV_ANCHOR 340
#define VAR_NEG_CACHE_SIZE 341
#define VAR_HARDEN_REFERRAL_PATH 342
#define VAR_PRIVATE_ADDRESS 343
#define VAR_PRIVATE_DOMAIN 344
#define VAR_REMOTE_CONTROL 345
#define VAR_CONTROL_ENABLE 346
#define VAR_CONTROL_INTERFACE 347
#define VAR_CONTROL_PORT 348
#define VAR_SERVER_KEY_FILE 349
#define VAR_SERVER_CERT_FILE 350
#define VAR_CONTROL_KEY_FILE 351
#define VAR_CONTROL_CERT_FILE 352
#define VAR_CONTROL_USE_CERT 353
#define VAR_EXTENDED_STATISTICS 354
#define VAR_LOCAL_DATA_PTR 355
#define VAR_JOSTLE_TIMEOUT 356
#define VAR_STUB_PRIME 357
#define VAR_UNWANTED_REPLY_THRESHOLD 358
#define VAR_LOG_TIME_ASCII 359
#define VAR_DOMAIN_INSECURE 360
#define VAR_PYTHON 361
#define VAR_PYTHON_SCRIPT 362
#define VAR_VAL_SIG_SKEW_MIN 363
#define VAR_VAL_SIG_SKEW_MAX 364
#define VAR_CACHE_MIN_TTL 365
#define VAR_VAL_LOG_LEVEL 366
#define VAR_AUTO_TRUST_ANCHOR_FILE 367
#define VAR_KEEP_MISSING 368
#define VAR_ADD_HOLDDOWN 369
#define VAR_DEL_HOLDDOWN 370
#define VAR_SO_RCVBUF 371
#define VAR_EDNS_BUFFER_SIZE 372
#define VAR_PREFETCH 373
#define VAR_PREFETCH_KEY 374
#define VAR_SO_SNDBUF 375
#define VAR_SO_REUSEPORT 376
#define VAR_HARDEN_BELOW_NXDOMAIN 377
#define VAR_IGNORE_CD_FLAG 378
#define VAR_LOG_QUERIES 379
#define VAR_LOG_REPLIES 380
#define VAR_TCP_UPSTREAM 381
#define VAR_SSL_UPSTREAM 382
#define VAR_SSL_SERVICE_KEY 383
#define VAR_SSL_SERVICE_PEM 384
#define VAR_SSL_PORT 385
#define VAR_FORWARD_FIRST 386
#define VAR_STUB_SSL_UPSTREAM 387
#define VAR_FORWARD_SSL_UPSTREAM 388
#define VAR_TLS_CERT_BUNDLE 389
#define VAR_STUB_FIRST 390
#define VAR_MINIMAL_RESPONSES 391
#define VAR_RRSET_ROUNDROBIN 392
#define VAR_MAX_UDP_SIZE 393
#define VAR_DELAY_CLOSE 394
#define VAR_UNBLOCK_LAN_ZONES 395
#define VAR_INSECURE_LAN_ZONES 396
#define VAR_INFRA_CACHE_MIN_RTT 397
#define VAR_DNS64_PREFIX 398
#define VAR_DNS64_SYNTHALL 399
#define VAR_DNSTAP 400
#define VAR_DNSTAP_ENABLE 401
#define VAR_DNSTAP_SOCKET_PATH 402
#define VAR_DNSTAP_SEND_IDENTITY 403
#define VAR_DNSTAP_SEND_VERSION 404
#define VAR_DNSTAP_IDENTITY 405
#define VAR_DNSTAP_VERSION 406
#define VAR_DNSTAP_LOG_RESOLVER_QUERY_MESSAGES 407
#define VAR_DNSTAP_LOG_RESOLVER_RESPONSE_MESSAGES 408
#define VAR_DNSTAP_LOG_CLIENT_QUERY_MESSAGES 409
#define VAR_DNSTAP_LOG_CLIENT_RESPONSE_MESSAGES 410
#define VAR_DNSTAP_LOG_FORWARDER_QUERY_MESSAGES 411
#define VAR_DNSTAP_LOG_FORWARDER_RESPONSE_MESSAGES 412
#define VAR_RESPONSE_IP_TAG 413
#define VAR_RESPONSE_IP 414
#define VAR_RESPONSE_IP_DATA 415
#define VAR_HARDEN_ALGO_DOWNGRADE 416
#define VAR_IP_TRANSPARENT 417
#define VAR_DISABLE_DNSSEC_LAME_CHECK 418
#define VAR_IP_RATELIMIT 419
#define VAR_IP_RATELIMIT_SLABS 420
#define VAR_IP_RATELIMIT_SIZE 421
#define VAR_RATELIMIT 422
#define VAR_RATELIMIT_SLABS 423
#define VAR_RATELIMIT_SIZE 424
#define VAR_RATELIMIT_FOR_DOMAIN 425
#define VAR_RATELIMIT_BELOW_DOMAIN 426
#define VAR_IP_RATELIMIT_FACTOR 427
#define VAR_RATELIMIT_FACTOR 428
#define VAR_SEND_CLIENT_SUBNET 429
#define VAR_CLIENT_SUBNET_ZONE 430
#define VAR_CLIENT_SUBNET_ALWAYS_FORWARD 431
#define VAR_CLIENT_SUBNET_OPCODE 432
#define VAR_MAX_CLIENT_SUBNET_IPV4 433
#define VAR_MAX_CLIENT_SUBNET_IPV6 434
#define VAR_CAPS_WHITELIST 435
#define VAR_CACHE_MAX_NEGATIVE_TTL 436
#define VAR_PERMIT_SMALL_HOLDDOWN 437
#define VAR_QNAME_MINIMISATION 438
#define VAR_QNAME_MINIMISATION_STRICT 439
#define VAR_IP_FREEBIND 440
#define VAR_DEFINE_TAG 441
#define VAR_LOCAL_ZONE_TAG 442
#define VAR_ACCESS_CONTROL_TAG 443
#define VAR_LOCAL_ZONE_OVERRIDE 444
#define VAR_ACCESS_CONTROL_TAG_ACTION 445
#define VAR_ACCESS_CONTROL_TAG_DATA 446
#define VAR_VIEW 447
#define VAR_ACCESS_CONTROL_VIEW 448
#define VAR_VIEW_FIRST 449
#define VAR_SERVE_EXPIRED 450
#define VAR_FAKE_DSA 451
#define VAR_FAKE_SHA1 452
#define VAR_LOG_IDENTITY 453
#define VAR_HIDE_TRUSTANCHOR 454
#define VAR_TRUST_ANCHOR_SIGNALING 455
#define VAR_AGGRESSIVE_NSEC 456
#define VAR_USE_SYSTEMD 457
#define VAR_SHM_ENABLE 458
#define VAR_SHM_KEY 459
#define VAR_DNSCRYPT 460
#define VAR_DNSCRYPT_ENABLE 461
#define VAR_DNSCRYPT_PORT 462
#define VAR_DNSCRYPT_PROVIDER 463
#define VAR_DNSCRYPT_SECRET_KEY 464
#define VAR_DNSCRYPT_PROVIDER_CERT 465
#define VAR_DNSCRYPT_PROVIDER_CERT_ROTATED 466
#define VAR_DNSCRYPT_SHARED_SECRET_CACHE_SIZE 467
#define VAR_DNSCRYPT_SHARED_SECRET_CACHE_SLABS 468
#define VAR_DNSCRYPT_NONCE_CACHE_SIZE 469
#define VAR_DNSCRYPT_NONCE_CACHE_SLABS 470
#define VAR_IPSECMOD_ENABLED 471
#define VAR_IPSECMOD_HOOK 472
#define VAR_IPSECMOD_IGNORE_BOGUS 473
#define VAR_IPSECMOD_MAX_TTL 474
#define VAR_IPSECMOD_WHITELIST 475
#define VAR_IPSECMOD_STRICT 476
#define VAR_CACHEDB 477
#define VAR_CACHEDB_BACKEND 478
#define VAR_CACHEDB_SECRETSEED 479
#define VAR_UDP_UPSTREAM_WITHOUT_DOWNSTREAM 480
#define VAR_FOR_UPSTREAM 481
#define VAR_AUTH_ZONE 482
#define VAR_ZONEFILE 483
#define VAR_MASTER 484
#define VAR_URL 485
#define VAR_FOR_DOWNSTREAM 486
#define VAR_FALLBACK_ENABLED 487
#define VAR_FORWARD_PREFERENCE 488
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    3,    3,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,    4,    5,
    5,  186,  186,  186,  186,  186,  186,    6,    7,    7,
  193,  193,  193,  193,  193,   14,   15,   15,  199,  199,
  199,  199,  199,  199,  199,   20,   21,   21,  207,  207,
  207,  207,  207,  207,  207,   23,   24,   83,   86,   95,
  172,  173,   25,  145,  146,  147,  148,  149,  150,   34,
   74,   26,   87,   88,   45,   67,   82,   27,   28,   30,
   31,   29,   32,   33,  118,  183,  119,  120,  121,  122,
  185,  168,   84,   73,   99,  116,  117,   35,   36,   37,
   38,   39,   75,   89,   90,  105,   61,   71,   62,  176,
  100,   55,   56,  175,   57,   58,  109,  113,  126,  134,
  155,  110,   68,   40,   41,   42,   97,  127,  128,  129,
   43,   44,   46,   47,   49,   50,   48,  132,   51,   52,
   53,   59,   78,  114,   92,  133,   85,  151,   93,   94,
  111,  112,   98,   54,   76,   79,   60,   63,  101,  102,
   77,  152,  103,   64,   65,   66,  184,  115,  165,  166,
  174,  104,   72,  106,  107,  108,  153,   69,   70,   91,
   80,   81,   96,  123,  124,  125,  130,  131,  156,  157,
  159,  161,  162,  160,  163,  169,  135,  136,  139,  140,
  137,  138,  141,  142,  144,  143,  154,  164,  177,  179,
  178,  180,  181,  182,  187,  188,  189,  191,  192,  190,
  194,  195,  196,  197,  215,  198,  208,  209,  210,  211,
  212,  213,  214,  200,  201,  204,  205,  202,  206,  203,
   10,   11,   11,  216,  216,  216,  216,  216,  216,  216,
  216,  217,  219,  218,  224,  220,  221,  222,  223,   12,
   13,   13,  225,  225,  225,  225,  225,  225,  225,  225,
  225,  225,  225,  225,  226,  227,  228,  229,  230,  231,
  232,  233,  234,  235,  236,  237,    8,    9,    9,  238,
  239,  158,  167,  170,  171,   16,   17,   17,  240,  240,
  240,  240,  240,  240,  240,  240,  240,  240,  241,  242,
  243,  245,  246,  244,  247,  248,  249,  250,   18,   19,
   19,  251,  251,  252,  253,
};
static const YYINT yylen[] = {                            2,
    0,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    1,    2,    0,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    0,    1,    1,    1,    1,    1,    1,    1,    2,    0,
    1,    1,    1,    1,    1,    1,    2,    0,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    0,    1,    1,
    1,    1,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    3,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    3,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    3,    4,    4,    4,    3,    3,    2,    2,    2,    2,
    2,    2,    3,    3,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    3,    2,    2,    2,
    1,    2,    0,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    2,    2,    2,    2,    2,    2,    2,    1,
    2,    0,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    1,    2,    0,    1,
    2,    2,    2,    3,    3,    1,    2,    0,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    1,    2,
    0,    1,    1,    2,    2,
};
static const YYINT yydefred[] = {                         1,
    0,   13,  179,  188,  401,  447,  420,  196,  456,  479,
  206,    2,   15,  181,  190,  449,  403,  422,  198,  458,
  481,  208,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,   16,   17,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
  100,  101,  102,  103,  104,  105,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,
  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,
  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,
  140,  141,  142,  143,  144,  145,  146,  147,  148,  149,
  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,
  170,  171,  172,  173,  174,  175,  176,  177,  178,    0,
    0,    0,    0,    0,    0,  180,  182,  183,  184,  185,
  186,  187,    0,    0,    0,    0,    0,  189,  191,  192,
  193,  194,  195,    0,  448,  450,    0,    0,    0,    0,
    0,    0,    0,    0,  402,  404,  405,  406,  407,  408,
  409,  410,  411,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  421,  423,  424,  425,  426,
  427,  428,  429,  430,  431,  432,  433,  434,    0,    0,
    0,    0,    0,    0,    0,  197,  199,  200,  201,  202,
  203,  204,  205,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  457,  459,  460,  461,  462,  463,  464,
  465,  466,  467,  468,    0,    0,  480,  482,  483,    0,
    0,    0,    0,    0,    0,    0,  207,  209,  210,  211,
  212,  213,  214,  215,  217,  216,  223,  232,  230,  238,
  239,  242,  240,  241,  243,  244,  258,  259,  260,  261,
  262,  284,  285,  286,  291,  292,  235,  293,  294,  297,
  295,  296,  299,  300,  301,  314,  272,  273,  275,  276,
  302,  317,  267,  269,  318,  324,  325,  326,  236,  283,
  338,  339,  268,  333,  254,  231,  263,  315,  321,  303,
    0,    0,  342,  237,  218,  253,  307,  219,  233,  234,
  264,  265,  340,  305,  309,  310,  220,  343,  287,  313,
  255,  271,  319,  320,  323,  332,  266,  336,  334,  335,
  277,  282,  311,  312,  278,  279,  304,  328,  256,  257,
  245,  247,  248,  249,  250,  251,  344,  345,  346,  288,
  289,  290,  298,  347,  348,    0,    0,    0,  306,  280,
  452,  357,  361,  359,  358,  362,  360,    0,    0,  365,
  366,  224,  225,  226,  227,  228,  229,  308,  322,  337,
  367,  368,  281,  349,    0,    0,    0,    0,    0,    0,
  329,  330,  331,  453,  274,  270,  327,  252,  221,  222,
  369,  371,  370,  372,  373,  374,  246,  375,  376,  377,
  380,  379,  378,  381,  382,  383,  384,  386,  451,  412,
  414,  413,  416,  417,  418,  419,  415,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,  394,
    0,  398,  399,    0,    0,  400,  469,  470,  471,  474,
  472,  473,  475,  476,  477,  478,  484,  485,  387,  392,
  388,  389,  390,  391,  393,  316,  341,  356,  454,  455,
  363,  364,  350,  351,    0,    0,    0,  355,  395,  396,
  397,  354,  352,  353,
};
static const YYINT yydgoto[] = {                          1,
   12,   13,   23,   14,   24,   15,   25,   16,   26,   17,
   27,   18,   28,   19,   29,   20,   30,   21,   31,   22,
   32,  196,  197,  198,  199,  200,  201,  202,  203,  204,
  205,  206,  207,  208,  209,  210,  211,  212,  213,  214,
  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,
  225,  226,  227,  228,  229,  230,  231,  232,  233,  234,
  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,
  245,  246,  247,  248,  249,  250,  251,  252,  253,  254,
  255,  256,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,
  295,  296,  297,  298,  299,  300,  301,  302,  303,  304,
  305,  306,  307,  308,  309,  310,  311,  312,  313,  314,
  315,  316,  317,  318,  319,  320,  321,  322,  323,  324,
  325,  326,  327,  328,  329,  330,  331,  332,  333,  334,
  335,  336,  337,  338,  339,  340,  341,  342,  343,  344,
  345,  346,  347,  348,  349,  350,  351,  352,  353,  354,
  355,  356,  357,  358,  359,  366,  367,  368,  369,  370,
  371,  372,  378,  379,  380,  381,  382,  383,  436,  437,
  438,  439,  440,  441,  442,  443,  477,  478,  479,  480,
  481,  482,  483,  484,    0,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  416,  417,  418,  419,  420,  421,
  422,  423,  424,  425,  426,  427,  428,  385,  386,  454,
  455,  456,  457,  458,  459,  460,  461,  462,  463,  464,
  467,  468,  469,
};
static const YYINT yysindex[] = {                         0,
 -265,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  292, -286, -280, -353, -264, -357, -288, -405,
 -463, -287, -247, -246, -245, -244, -243, -240, -239, -238,
 -237, -236, -235, -233, -232, -231, -230, -229, -227, -226,
 -225, -224, -223, -196, -195, -194, -192, -191, -188, -187,
 -186, -185, -183, -174, -173, -172, -171, -170, -169, -167,
 -166, -165, -164, -162, -161, -159, -157, -155, -154, -153,
 -152, -151, -150, -149, -148, -147, -146, -145, -144, -143,
 -142, -141, -140, -139, -136, -135, -134, -133, -132, -131,
 -130, -128, -127, -126, -125, -124, -123, -122, -121, -120,
 -119, -118, -117, -116, -115, -114, -113, -112, -111, -110,
 -109, -108, -107, -106, -105, -104, -102, -101, -100,  -99,
  -98,  -97,  -96,  -95,  -94,  -93,  -92,  -91,  -90,  -89,
  -88,  -87,  -86,  -85,  -84,  -83,  -81,  -80,  -79,  -78,
  -77,  -76,  -75,  -74,  -73,  -72,  -71,  -63,  -62,  -61,
  -60,  -59,  -58,  -57,  -56,  -55,  -54,  -53,  -51,  -50,
  -49,  -48,  -46,  -45,  -44,  -43,  -42,  -41,  -40,  -39,
  -38,  -37,  -36,  -35,  -34,  -33,  -32,  -31,  -30,  -29,
  -28,  -27,  -26,  -25,  -24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -23,
  -22,  -21,  -20,  -19,  -18,    0,    0,    0,    0,    0,
    0,    0,  -17,  -16,  -15,  -14,  -13,    0,    0,    0,
    0,    0,    0,  -12,    0,    0,  -11,  -10,   -9,   -8,
   -7,   -6,   -5,   -4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -3,   -2,   -1,    7,    8,    9,   10,
   11,   15,   16,   17,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   20,
   21,   22,   23,   24,   25,    0,    0,    0,    0,    0,
    0,    0,    0,   26,   27,   28,   29,   30,   31,   37,
   45,   46,   47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,   51,    0,    0,    0,   52,
   53,   54,   55,   56,   57,   58,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   59,   60,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   61,   62,   63,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   64,   65,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   68,   69,   70,   71,   72,   73,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   77,    0,    0,   78,   79,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   80,   81,   87,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    2,    3,    4,    5,   12,   13,   66,
   74,   75,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 772
static const YYINT yytable[] = {                          2,
    3,    4,    5,    6,    7,  429,  470,  360,  384,  361,
  362,    8,    9,  373,  465,  466,  485,  486,  487,  488,
  489,  374,  375,  490,  491,  492,  493,  494,  495,    3,
  496,  497,  498,  499,  500,    4,  501,  502,  503,  504,
  505,  430,  431,  404,  405,  406,  407,  408,  409,  410,
  411,  412,  413,  414,  415,  444,  445,  446,  447,  448,
  449,  450,  451,  452,  453,   10,  432,  506,  507,  508,
  363,  509,  510,   11,   12,  511,  512,  513,  514,    5,
  515,  387,  388,  389,  390,  391,  392,  393,  394,  516,
  517,  518,  519,  520,  521,    6,  522,  523,  524,  525,
  364,  526,  527,  365,  528,  376,  529,  377,  530,  531,
  532,  533,  534,  535,  536,  537,  538,  539,  540,  541,
  542,  543,  544,  545,  546,  433,  434,  547,  548,  549,
  550,  551,  552,  553,    7,  554,  555,  556,  557,  558,
  559,  560,  561,  562,  563,  564,  565,  566,  567,  568,
  569,  570,  571,  572,  573,  574,  575,  576,  577,  578,
  435,  579,  580,  581,  582,  583,  584,  585,  586,  587,
  588,  589,  590,  591,  592,  593,  594,  595,  596,  597,
  598,    8,  599,  600,  601,  602,  603,  604,  605,  606,
  607,  608,  609,  471,    9,  472,  473,  474,  475,  476,
  610,  611,  612,  613,  614,  615,  616,  617,  618,  619,
  620,   10,  621,  622,  623,  624,   11,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,  645,  646,  647,
  648,  649,  650,  651,  652,  653,  654,  655,  656,  657,
  658,  659,  660,  661,  662,  663,  664,  665,  666,  667,
  668,  669,  670,    0,    0,    3,    4,    5,    6,    7,
  671,  672,  673,  674,  675,    0,    8,    9,  676,  677,
  678,  679,  680,  681,  682,  683,  684,  685,  686,  687,
  688,  689,  690,  691,  692,    3,    4,    5,    6,    7,
  693,    3,    4,    5,    6,    7,    8,    9,  694,  695,
  696,  697,    8,    9,  698,  699,  700,  701,  702,  703,
  704,  705,  706,  707,  708,  709,  710,  711,  712,    0,
   10,  713,  714,  715,  716,  717,  718,    0,   11,   12,
  719,  720,  721,  722,  723,    3,    4,    5,    6,    7,
  724,    0,    0,    0,    0,    0,    8,    9,    0,    0,
   10,    3,    4,    5,    6,    7,   10,    0,   11,   12,
    0,    0,    8,    9,   11,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    4,    5,    6,    7,    0,    0,    0,    0,    0,
   10,    8,    9,    0,    0,    0,    0,    0,   11,   12,
    0,    0,    0,    0,    0,    0,   10,    0,    0,    0,
    0,    0,    0,    0,   11,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,    4,    5,
    6,    7,    0,    0,    0,    0,    0,    0,    8,    9,
    3,    4,    5,    6,    7,   10,    0,    0,    0,    0,
    0,    8,    9,   11,   12,    0,    0,    3,    4,    5,
    6,    7,    3,    4,    5,    6,    7,    0,    8,    9,
    0,    0,    0,    8,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   10,    0,    0,    0,    0,    0,    0,    0,
   11,   12,    0,    0,    0,   10,    0,    0,    0,    0,
    0,    0,    0,   11,   12,    0,    0,    0,    0,    0,
    0,    0,   10,    0,    0,    0,    0,   10,    0,    0,
   11,   12,    0,    0,    0,   11,   12,   33,   34,   35,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
   56,   57,   58,   59,   60,    0,    0,    0,    0,   61,
   62,   63,    0,    0,    0,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
   99,  100,  101,  102,  103,  104,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  105,  106,  107,    0,  108,
  109,  110,    0,    0,  111,  112,  113,  114,  115,  116,
  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,
  127,  128,  129,  130,  131,  132,  133,    0,    0,    0,
  134,    0,  135,  136,  137,  138,  139,  140,  141,  142,
  143,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  144,  145,  146,  147,  148,  149,
  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,
  170,  171,  172,  173,  174,  175,  176,  177,    0,  178,
    0,  179,  180,  181,  182,  183,  184,  185,  186,  187,
  188,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  189,  190,  191,  192,  193,  194,    0,    0,
    0,  195,
};
static const YYINT yycheck[] = {                        265,
    0,    0,    0,    0,    0,  294,  294,  294,  362,  296,
  297,    0,    0,  294,  478,  479,  264,  264,  264,  264,
  264,  302,  303,  264,  264,  264,  264,  264,  264,  295,
  264,  264,  264,  264,  264,  301,  264,  264,  264,  264,
  264,  330,  331,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,  411,  412,  461,  462,  463,  464,  465,
  466,  467,  468,  469,  470,    0,  355,  264,  264,  264,
  357,  264,  264,    0,    0,  264,  264,  264,  264,  345,
  264,  346,  347,  348,  349,  350,  351,  352,  353,  264,
  264,  264,  264,  264,  264,  361,  264,  264,  264,  264,
  387,  264,  264,  390,  264,  386,  264,  388,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  414,  415,  264,  264,  264,
  264,  264,  264,  264,  400,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  449,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  447,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  481,  460,  483,  484,  485,  486,  487,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  477,  264,  264,  264,  264,  482,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,   -1,   -1,  265,  265,  265,  265,  265,
  264,  264,  264,  264,  264,   -1,  265,  265,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  295,  295,  295,  295,  295,
  264,  301,  301,  301,  301,  301,  295,  295,  264,  264,
  264,  264,  301,  301,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,   -1,
  265,  264,  264,  264,  264,  264,  264,   -1,  265,  265,
  264,  264,  264,  264,  264,  345,  345,  345,  345,  345,
  264,   -1,   -1,   -1,   -1,   -1,  345,  345,   -1,   -1,
  295,  361,  361,  361,  361,  361,  301,   -1,  295,  295,
   -1,   -1,  361,  361,  301,  301,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  400,  400,  400,  400,  400,   -1,   -1,   -1,   -1,   -1,
  345,  400,  400,   -1,   -1,   -1,   -1,   -1,  345,  345,
   -1,   -1,   -1,   -1,   -1,   -1,  361,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  361,  361,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  447,  447,  447,
  447,  447,   -1,   -1,   -1,   -1,   -1,   -1,  447,  447,
  460,  460,  460,  460,  460,  400,   -1,   -1,   -1,   -1,
   -1,  460,  460,  400,  400,   -1,   -1,  477,  477,  477,
  477,  477,  482,  482,  482,  482,  482,   -1,  477,  477,
   -1,   -1,   -1,  482,  482,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  447,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  447,  447,   -1,   -1,   -1,  460,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  460,  460,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  477,   -1,   -1,   -1,   -1,  482,   -1,   -1,
  477,  477,   -1,   -1,   -1,  482,  482,  266,  267,  268,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,   -1,   -1,   -1,   -1,  298,
  299,  300,   -1,   -1,   -1,  304,  305,  306,  307,  308,
  309,  310,  311,  312,  313,  314,  315,  316,  317,  318,
  319,  320,  321,  322,  323,  324,  325,  326,  327,  328,
  329,  330,  331,  332,  333,  334,  335,  336,  337,  338,
  339,  340,  341,  342,  343,  344,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  354,  355,  356,   -1,  358,
  359,  360,   -1,   -1,  363,  364,  365,  366,  367,  368,
  369,  370,  371,  372,  373,  374,  375,  376,  377,  378,
  379,  380,  381,  382,  383,  384,  385,   -1,   -1,   -1,
  389,   -1,  391,  392,  393,  394,  395,  396,  397,  398,
  399,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  413,  414,  415,  416,  417,  418,
  419,  420,  421,  422,  423,  424,  425,  426,  427,  428,
  429,  430,  431,  432,  433,  434,  435,  436,  437,  438,
  439,  440,  441,  442,  443,  444,  445,  446,   -1,  448,
   -1,  450,  451,  452,  453,  454,  455,  456,  457,  458,
  459,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  471,  472,  473,  474,  475,  476,   -1,   -1,
   -1,  480,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 488
#define YYUNDFTOKEN 744
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SPACE","LETTER","NEWLINE",
"COMMENT","COLON","ANY","ZONESTR","STRING_ARG","VAR_SERVER","VAR_VERBOSITY",
"VAR_NUM_THREADS","VAR_PORT","VAR_OUTGOING_RANGE","VAR_INTERFACE","VAR_DO_IP4",
"VAR_DO_IP6","VAR_PREFER_IP6","VAR_DO_UDP","VAR_DO_TCP","VAR_TCP_MSS",
"VAR_OUTGOING_TCP_MSS","VAR_CHROOT","VAR_USERNAME","VAR_DIRECTORY",
"VAR_LOGFILE","VAR_PIDFILE","VAR_MSG_CACHE_SIZE","VAR_MSG_CACHE_SLABS",
"VAR_NUM_QUERIES_PER_THREAD","VAR_RRSET_CACHE_SIZE","VAR_RRSET_CACHE_SLABS",
"VAR_OUTGOING_NUM_TCP","VAR_INFRA_HOST_TTL","VAR_INFRA_LAME_TTL",
"VAR_INFRA_CACHE_SLABS","VAR_INFRA_CACHE_NUMHOSTS","VAR_INFRA_CACHE_LAME_SIZE",
"VAR_NAME","VAR_STUB_ZONE","VAR_STUB_HOST","VAR_STUB_ADDR",
"VAR_TARGET_FETCH_POLICY","VAR_HARDEN_SHORT_BUFSIZE","VAR_HARDEN_LARGE_QUERIES",
"VAR_FORWARD_ZONE","VAR_FORWARD_HOST","VAR_FORWARD_ADDR",
"VAR_DO_NOT_QUERY_ADDRESS","VAR_HIDE_IDENTITY","VAR_HIDE_VERSION",
"VAR_IDENTITY","VAR_VERSION","VAR_HARDEN_GLUE","VAR_MODULE_CONF",
"VAR_TRUST_ANCHOR_FILE","VAR_TRUST_ANCHOR","VAR_VAL_OVERRIDE_DATE",
"VAR_BOGUS_TTL","VAR_VAL_CLEAN_ADDITIONAL","VAR_VAL_PERMISSIVE_MODE",
"VAR_INCOMING_NUM_TCP","VAR_MSG_BUFFER_SIZE","VAR_KEY_CACHE_SIZE",
"VAR_KEY_CACHE_SLABS","VAR_TRUSTED_KEYS_FILE",
"VAR_VAL_NSEC3_KEYSIZE_ITERATIONS","VAR_USE_SYSLOG","VAR_OUTGOING_INTERFACE",
"VAR_ROOT_HINTS","VAR_DO_NOT_QUERY_LOCALHOST","VAR_CACHE_MAX_TTL",
"VAR_HARDEN_DNSSEC_STRIPPED","VAR_ACCESS_CONTROL","VAR_LOCAL_ZONE",
"VAR_LOCAL_DATA","VAR_INTERFACE_AUTOMATIC","VAR_STATISTICS_INTERVAL",
"VAR_DO_DAEMONIZE","VAR_USE_CAPS_FOR_ID","VAR_STATISTICS_CUMULATIVE",
"VAR_OUTGOING_PORT_PERMIT","VAR_OUTGOING_PORT_AVOID","VAR_DLV_ANCHOR_FILE",
"VAR_DLV_ANCHOR","VAR_NEG_CACHE_SIZE","VAR_HARDEN_REFERRAL_PATH",
"VAR_PRIVATE_ADDRESS","VAR_PRIVATE_DOMAIN","VAR_REMOTE_CONTROL",
"VAR_CONTROL_ENABLE","VAR_CONTROL_INTERFACE","VAR_CONTROL_PORT",
"VAR_SERVER_KEY_FILE","VAR_SERVER_CERT_FILE","VAR_CONTROL_KEY_FILE",
"VAR_CONTROL_CERT_FILE","VAR_CONTROL_USE_CERT","VAR_EXTENDED_STATISTICS",
"VAR_LOCAL_DATA_PTR","VAR_JOSTLE_TIMEOUT","VAR_STUB_PRIME",
"VAR_UNWANTED_REPLY_THRESHOLD","VAR_LOG_TIME_ASCII","VAR_DOMAIN_INSECURE",
"VAR_PYTHON","VAR_PYTHON_SCRIPT","VAR_VAL_SIG_SKEW_MIN","VAR_VAL_SIG_SKEW_MAX",
"VAR_CACHE_MIN_TTL","VAR_VAL_LOG_LEVEL","VAR_AUTO_TRUST_ANCHOR_FILE",
"VAR_KEEP_MISSING","VAR_ADD_HOLDDOWN","VAR_DEL_HOLDDOWN","VAR_SO_RCVBUF",
"VAR_EDNS_BUFFER_SIZE","VAR_PREFETCH","VAR_PREFETCH_KEY","VAR_SO_SNDBUF",
"VAR_SO_REUSEPORT","VAR_HARDEN_BELOW_NXDOMAIN","VAR_IGNORE_CD_FLAG",
"VAR_LOG_QUERIES","VAR_LOG_REPLIES","VAR_TCP_UPSTREAM","VAR_SSL_UPSTREAM",
"VAR_SSL_SERVICE_KEY","VAR_SSL_SERVICE_PEM","VAR_SSL_PORT","VAR_FORWARD_FIRST",
"VAR_STUB_SSL_UPSTREAM","VAR_FORWARD_SSL_UPSTREAM","VAR_TLS_CERT_BUNDLE",
"VAR_STUB_FIRST","VAR_MINIMAL_RESPONSES","VAR_RRSET_ROUNDROBIN",
"VAR_MAX_UDP_SIZE","VAR_DELAY_CLOSE","VAR_UNBLOCK_LAN_ZONES",
"VAR_INSECURE_LAN_ZONES","VAR_INFRA_CACHE_MIN_RTT","VAR_DNS64_PREFIX",
"VAR_DNS64_SYNTHALL","VAR_DNSTAP","VAR_DNSTAP_ENABLE","VAR_DNSTAP_SOCKET_PATH",
"VAR_DNSTAP_SEND_IDENTITY","VAR_DNSTAP_SEND_VERSION","VAR_DNSTAP_IDENTITY",
"VAR_DNSTAP_VERSION","VAR_DNSTAP_LOG_RESOLVER_QUERY_MESSAGES",
"VAR_DNSTAP_LOG_RESOLVER_RESPONSE_MESSAGES",
"VAR_DNSTAP_LOG_CLIENT_QUERY_MESSAGES",
"VAR_DNSTAP_LOG_CLIENT_RESPONSE_MESSAGES",
"VAR_DNSTAP_LOG_FORWARDER_QUERY_MESSAGES",
"VAR_DNSTAP_LOG_FORWARDER_RESPONSE_MESSAGES","VAR_RESPONSE_IP_TAG",
"VAR_RESPONSE_IP","VAR_RESPONSE_IP_DATA","VAR_HARDEN_ALGO_DOWNGRADE",
"VAR_IP_TRANSPARENT","VAR_DISABLE_DNSSEC_LAME_CHECK","VAR_IP_RATELIMIT",
"VAR_IP_RATELIMIT_SLABS","VAR_IP_RATELIMIT_SIZE","VAR_RATELIMIT",
"VAR_RATELIMIT_SLABS","VAR_RATELIMIT_SIZE","VAR_RATELIMIT_FOR_DOMAIN",
"VAR_RATELIMIT_BELOW_DOMAIN","VAR_IP_RATELIMIT_FACTOR","VAR_RATELIMIT_FACTOR",
"VAR_SEND_CLIENT_SUBNET","VAR_CLIENT_SUBNET_ZONE",
"VAR_CLIENT_SUBNET_ALWAYS_FORWARD","VAR_CLIENT_SUBNET_OPCODE",
"VAR_MAX_CLIENT_SUBNET_IPV4","VAR_MAX_CLIENT_SUBNET_IPV6","VAR_CAPS_WHITELIST",
"VAR_CACHE_MAX_NEGATIVE_TTL","VAR_PERMIT_SMALL_HOLDDOWN",
"VAR_QNAME_MINIMISATION","VAR_QNAME_MINIMISATION_STRICT","VAR_IP_FREEBIND",
"VAR_DEFINE_TAG","VAR_LOCAL_ZONE_TAG","VAR_ACCESS_CONTROL_TAG",
"VAR_LOCAL_ZONE_OVERRIDE","VAR_ACCESS_CONTROL_TAG_ACTION",
"VAR_ACCESS_CONTROL_TAG_DATA","VAR_VIEW","VAR_ACCESS_CONTROL_VIEW",
"VAR_VIEW_FIRST","VAR_SERVE_EXPIRED","VAR_FAKE_DSA","VAR_FAKE_SHA1",
"VAR_LOG_IDENTITY","VAR_HIDE_TRUSTANCHOR","VAR_TRUST_ANCHOR_SIGNALING",
"VAR_AGGRESSIVE_NSEC","VAR_USE_SYSTEMD","VAR_SHM_ENABLE","VAR_SHM_KEY",
"VAR_DNSCRYPT","VAR_DNSCRYPT_ENABLE","VAR_DNSCRYPT_PORT",
"VAR_DNSCRYPT_PROVIDER","VAR_DNSCRYPT_SECRET_KEY","VAR_DNSCRYPT_PROVIDER_CERT",
"VAR_DNSCRYPT_PROVIDER_CERT_ROTATED","VAR_DNSCRYPT_SHARED_SECRET_CACHE_SIZE",
"VAR_DNSCRYPT_SHARED_SECRET_CACHE_SLABS","VAR_DNSCRYPT_NONCE_CACHE_SIZE",
"VAR_DNSCRYPT_NONCE_CACHE_SLABS","VAR_IPSECMOD_ENABLED","VAR_IPSECMOD_HOOK",
"VAR_IPSECMOD_IGNORE_BOGUS","VAR_IPSECMOD_MAX_TTL","VAR_IPSECMOD_WHITELIST",
"VAR_IPSECMOD_STRICT","VAR_CACHEDB","VAR_CACHEDB_BACKEND",
"VAR_CACHEDB_SECRETSEED","VAR_UDP_UPSTREAM_WITHOUT_DOWNSTREAM",
"VAR_FOR_UPSTREAM","VAR_AUTH_ZONE","VAR_ZONEFILE","VAR_MASTER","VAR_URL",
"VAR_FOR_DOWNSTREAM","VAR_FALLBACK_ENABLED","VAR_FORWARD_PREFERENCE",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : toplevelvars",
"toplevelvars :",
"toplevelvars : toplevelvars toplevelvar",
"toplevelvar : serverstart contents_server",
"toplevelvar : stubstart contents_stub",
"toplevelvar : forwardstart contents_forward",
"toplevelvar : pythonstart contents_py",
"toplevelvar : rcstart contents_rc",
"toplevelvar : dtstart contents_dt",
"toplevelvar : viewstart contents_view",
"toplevelvar : dnscstart contents_dnsc",
"toplevelvar : cachedbstart contents_cachedb",
"toplevelvar : authstart contents_auth",
"serverstart : VAR_SERVER",
"contents_server : contents_server content_server",
"contents_server :",
"content_server : server_num_threads",
"content_server : server_verbosity",
"content_server : server_port",
"content_server : server_outgoing_range",
"content_server : server_do_ip4",
"content_server : server_do_ip6",
"content_server : server_prefer_ip6",
"content_server : server_do_udp",
"content_server : server_do_tcp",
"content_server : server_tcp_mss",
"content_server : server_outgoing_tcp_mss",
"content_server : server_interface",
"content_server : server_chroot",
"content_server : server_username",
"content_server : server_directory",
"content_server : server_logfile",
"content_server : server_pidfile",
"content_server : server_msg_cache_size",
"content_server : server_msg_cache_slabs",
"content_server : server_num_queries_per_thread",
"content_server : server_rrset_cache_size",
"content_server : server_rrset_cache_slabs",
"content_server : server_outgoing_num_tcp",
"content_server : server_infra_host_ttl",
"content_server : server_infra_lame_ttl",
"content_server : server_infra_cache_slabs",
"content_server : server_infra_cache_numhosts",
"content_server : server_infra_cache_lame_size",
"content_server : server_target_fetch_policy",
"content_server : server_harden_short_bufsize",
"content_server : server_harden_large_queries",
"content_server : server_do_not_query_address",
"content_server : server_hide_identity",
"content_server : server_hide_version",
"content_server : server_identity",
"content_server : server_version",
"content_server : server_harden_glue",
"content_server : server_module_conf",
"content_server : server_trust_anchor_file",
"content_server : server_trust_anchor",
"content_server : server_val_override_date",
"content_server : server_bogus_ttl",
"content_server : server_val_clean_additional",
"content_server : server_val_permissive_mode",
"content_server : server_incoming_num_tcp",
"content_server : server_msg_buffer_size",
"content_server : server_key_cache_size",
"content_server : server_key_cache_slabs",
"content_server : server_trusted_keys_file",
"content_server : server_val_nsec3_keysize_iterations",
"content_server : server_use_syslog",
"content_server : server_outgoing_interface",
"content_server : server_root_hints",
"content_server : server_do_not_query_localhost",
"content_server : server_cache_max_ttl",
"content_server : server_harden_dnssec_stripped",
"content_server : server_access_control",
"content_server : server_local_zone",
"content_server : server_local_data",
"content_server : server_interface_automatic",
"content_server : server_statistics_interval",
"content_server : server_do_daemonize",
"content_server : server_use_caps_for_id",
"content_server : server_statistics_cumulative",
"content_server : server_outgoing_port_permit",
"content_server : server_outgoing_port_avoid",
"content_server : server_dlv_anchor_file",
"content_server : server_dlv_anchor",
"content_server : server_neg_cache_size",
"content_server : server_harden_referral_path",
"content_server : server_private_address",
"content_server : server_private_domain",
"content_server : server_extended_statistics",
"content_server : server_local_data_ptr",
"content_server : server_jostle_timeout",
"content_server : server_unwanted_reply_threshold",
"content_server : server_log_time_ascii",
"content_server : server_domain_insecure",
"content_server : server_val_sig_skew_min",
"content_server : server_val_sig_skew_max",
"content_server : server_cache_min_ttl",
"content_server : server_val_log_level",
"content_server : server_auto_trust_anchor_file",
"content_server : server_add_holddown",
"content_server : server_del_holddown",
"content_server : server_keep_missing",
"content_server : server_so_rcvbuf",
"content_server : server_edns_buffer_size",
"content_server : server_prefetch",
"content_server : server_prefetch_key",
"content_server : server_so_sndbuf",
"content_server : server_harden_below_nxdomain",
"content_server : server_ignore_cd_flag",
"content_server : server_log_queries",
"content_server : server_log_replies",
"content_server : server_tcp_upstream",
"content_server : server_ssl_upstream",
"content_server : server_ssl_service_key",
"content_server : server_ssl_service_pem",
"content_server : server_ssl_port",
"content_server : server_minimal_responses",
"content_server : server_rrset_roundrobin",
"content_server : server_max_udp_size",
"content_server : server_so_reuseport",
"content_server : server_delay_close",
"content_server : server_unblock_lan_zones",
"content_server : server_insecure_lan_zones",
"content_server : server_dns64_prefix",
"content_server : server_dns64_synthall",
"content_server : server_infra_cache_min_rtt",
"content_server : server_harden_algo_downgrade",
"content_server : server_ip_transparent",
"content_server : server_ip_ratelimit",
"content_server : server_ratelimit",
"content_server : server_ip_ratelimit_slabs",
"content_server : server_ratelimit_slabs",
"content_server : server_ip_ratelimit_size",
"content_server : server_ratelimit_size",
"content_server : server_ratelimit_for_domain",
"content_server : server_ratelimit_below_domain",
"content_server : server_ratelimit_factor",
"content_server : server_ip_ratelimit_factor",
"content_server : server_send_client_subnet",
"content_server : server_client_subnet_zone",
"content_server : server_client_subnet_always_forward",
"content_server : server_client_subnet_opcode",
"content_server : server_max_client_subnet_ipv4",
"content_server : server_max_client_subnet_ipv6",
"content_server : server_caps_whitelist",
"content_server : server_cache_max_negative_ttl",
"content_server : server_permit_small_holddown",
"content_server : server_qname_minimisation",
"content_server : server_ip_freebind",
"content_server : server_define_tag",
"content_server : server_local_zone_tag",
"content_server : server_disable_dnssec_lame_check",
"content_server : server_access_control_tag",
"content_server : server_local_zone_override",
"content_server : server_access_control_tag_action",
"content_server : server_access_control_tag_data",
"content_server : server_access_control_view",
"content_server : server_qname_minimisation_strict",
"content_server : server_serve_expired",
"content_server : server_fake_dsa",
"content_server : server_log_identity",
"content_server : server_use_systemd",
"content_server : server_response_ip_tag",
"content_server : server_response_ip",
"content_server : server_response_ip_data",
"content_server : server_shm_enable",
"content_server : server_shm_key",
"content_server : server_fake_sha1",
"content_server : server_hide_trustanchor",
"content_server : server_trust_anchor_signaling",
"content_server : server_ipsecmod_enabled",
"content_server : server_ipsecmod_hook",
"content_server : server_ipsecmod_ignore_bogus",
"content_server : server_ipsecmod_max_ttl",
"content_server : server_ipsecmod_whitelist",
"content_server : server_ipsecmod_strict",
"content_server : server_udp_upstream_without_downstream",
"content_server : server_aggressive_nsec",
"content_server : server_tls_cert_bundle",
"stubstart : VAR_STUB_ZONE",
"contents_stub : contents_stub content_stub",
"contents_stub :",
"content_stub : stub_name",
"content_stub : stub_host",
"content_stub : stub_addr",
"content_stub : stub_prime",
"content_stub : stub_first",
"content_stub : stub_ssl_upstream",
"forwardstart : VAR_FORWARD_ZONE",
"contents_forward : contents_forward content_forward",
"contents_forward :",
"content_forward : forward_name",
"content_forward : forward_host",
"content_forward : forward_addr",
"content_forward : forward_first",
"content_forward : forward_ssl_upstream",
"viewstart : VAR_VIEW",
"contents_view : contents_view content_view",
"contents_view :",
"content_view : view_name",
"content_view : view_local_zone",
"content_view : view_local_data",
"content_view : view_first",
"content_view : view_response_ip",
"content_view : view_response_ip_data",
"content_view : view_local_data_ptr",
"authstart : VAR_AUTH_ZONE",
"contents_auth : contents_auth content_auth",
"contents_auth :",
"content_auth : auth_name",
"content_auth : auth_zonefile",
"content_auth : auth_master",
"content_auth : auth_url",
"content_auth : auth_for_downstream",
"content_auth : auth_for_upstream",
"content_auth : auth_fallback_enabled",
"server_num_threads : VAR_NUM_THREADS STRING_ARG",
"server_verbosity : VAR_VERBOSITY STRING_ARG",
"server_statistics_interval : VAR_STATISTICS_INTERVAL STRING_ARG",
"server_statistics_cumulative : VAR_STATISTICS_CUMULATIVE STRING_ARG",
"server_extended_statistics : VAR_EXTENDED_STATISTICS STRING_ARG",
"server_shm_enable : VAR_SHM_ENABLE STRING_ARG",
"server_shm_key : VAR_SHM_KEY STRING_ARG",
"server_port : VAR_PORT STRING_ARG",
"server_send_client_subnet : VAR_SEND_CLIENT_SUBNET STRING_ARG",
"server_client_subnet_zone : VAR_CLIENT_SUBNET_ZONE STRING_ARG",
"server_client_subnet_always_forward : VAR_CLIENT_SUBNET_ALWAYS_FORWARD STRING_ARG",
"server_client_subnet_opcode : VAR_CLIENT_SUBNET_OPCODE STRING_ARG",
"server_max_client_subnet_ipv4 : VAR_MAX_CLIENT_SUBNET_IPV4 STRING_ARG",
"server_max_client_subnet_ipv6 : VAR_MAX_CLIENT_SUBNET_IPV6 STRING_ARG",
"server_interface : VAR_INTERFACE STRING_ARG",
"server_outgoing_interface : VAR_OUTGOING_INTERFACE STRING_ARG",
"server_outgoing_range : VAR_OUTGOING_RANGE STRING_ARG",
"server_outgoing_port_permit : VAR_OUTGOING_PORT_PERMIT STRING_ARG",
"server_outgoing_port_avoid : VAR_OUTGOING_PORT_AVOID STRING_ARG",
"server_outgoing_num_tcp : VAR_OUTGOING_NUM_TCP STRING_ARG",
"server_incoming_num_tcp : VAR_INCOMING_NUM_TCP STRING_ARG",
"server_interface_automatic : VAR_INTERFACE_AUTOMATIC STRING_ARG",
"server_do_ip4 : VAR_DO_IP4 STRING_ARG",
"server_do_ip6 : VAR_DO_IP6 STRING_ARG",
"server_do_udp : VAR_DO_UDP STRING_ARG",
"server_do_tcp : VAR_DO_TCP STRING_ARG",
"server_prefer_ip6 : VAR_PREFER_IP6 STRING_ARG",
"server_tcp_mss : VAR_TCP_MSS STRING_ARG",
"server_outgoing_tcp_mss : VAR_OUTGOING_TCP_MSS STRING_ARG",
"server_tcp_upstream : VAR_TCP_UPSTREAM STRING_ARG",
"server_udp_upstream_without_downstream : VAR_UDP_UPSTREAM_WITHOUT_DOWNSTREAM STRING_ARG",
"server_ssl_upstream : VAR_SSL_UPSTREAM STRING_ARG",
"server_ssl_service_key : VAR_SSL_SERVICE_KEY STRING_ARG",
"server_ssl_service_pem : VAR_SSL_SERVICE_PEM STRING_ARG",
"server_ssl_port : VAR_SSL_PORT STRING_ARG",
"server_tls_cert_bundle : VAR_TLS_CERT_BUNDLE STRING_ARG",
"server_use_systemd : VAR_USE_SYSTEMD STRING_ARG",
"server_do_daemonize : VAR_DO_DAEMONIZE STRING_ARG",
"server_use_syslog : VAR_USE_SYSLOG STRING_ARG",
"server_log_time_ascii : VAR_LOG_TIME_ASCII STRING_ARG",
"server_log_queries : VAR_LOG_QUERIES STRING_ARG",
"server_log_replies : VAR_LOG_REPLIES STRING_ARG",
"server_chroot : VAR_CHROOT STRING_ARG",
"server_username : VAR_USERNAME STRING_ARG",
"server_directory : VAR_DIRECTORY STRING_ARG",
"server_logfile : VAR_LOGFILE STRING_ARG",
"server_pidfile : VAR_PIDFILE STRING_ARG",
"server_root_hints : VAR_ROOT_HINTS STRING_ARG",
"server_dlv_anchor_file : VAR_DLV_ANCHOR_FILE STRING_ARG",
"server_dlv_anchor : VAR_DLV_ANCHOR STRING_ARG",
"server_auto_trust_anchor_file : VAR_AUTO_TRUST_ANCHOR_FILE STRING_ARG",
"server_trust_anchor_file : VAR_TRUST_ANCHOR_FILE STRING_ARG",
"server_trusted_keys_file : VAR_TRUSTED_KEYS_FILE STRING_ARG",
"server_trust_anchor : VAR_TRUST_ANCHOR STRING_ARG",
"server_trust_anchor_signaling : VAR_TRUST_ANCHOR_SIGNALING STRING_ARG",
"server_domain_insecure : VAR_DOMAIN_INSECURE STRING_ARG",
"server_hide_identity : VAR_HIDE_IDENTITY STRING_ARG",
"server_hide_version : VAR_HIDE_VERSION STRING_ARG",
"server_hide_trustanchor : VAR_HIDE_TRUSTANCHOR STRING_ARG",
"server_identity : VAR_IDENTITY STRING_ARG",
"server_version : VAR_VERSION STRING_ARG",
"server_so_rcvbuf : VAR_SO_RCVBUF STRING_ARG",
"server_so_sndbuf : VAR_SO_SNDBUF STRING_ARG",
"server_so_reuseport : VAR_SO_REUSEPORT STRING_ARG",
"server_ip_transparent : VAR_IP_TRANSPARENT STRING_ARG",
"server_ip_freebind : VAR_IP_FREEBIND STRING_ARG",
"server_edns_buffer_size : VAR_EDNS_BUFFER_SIZE STRING_ARG",
"server_msg_buffer_size : VAR_MSG_BUFFER_SIZE STRING_ARG",
"server_msg_cache_size : VAR_MSG_CACHE_SIZE STRING_ARG",
"server_msg_cache_slabs : VAR_MSG_CACHE_SLABS STRING_ARG",
"server_num_queries_per_thread : VAR_NUM_QUERIES_PER_THREAD STRING_ARG",
"server_jostle_timeout : VAR_JOSTLE_TIMEOUT STRING_ARG",
"server_delay_close : VAR_DELAY_CLOSE STRING_ARG",
"server_unblock_lan_zones : VAR_UNBLOCK_LAN_ZONES STRING_ARG",
"server_insecure_lan_zones : VAR_INSECURE_LAN_ZONES STRING_ARG",
"server_rrset_cache_size : VAR_RRSET_CACHE_SIZE STRING_ARG",
"server_rrset_cache_slabs : VAR_RRSET_CACHE_SLABS STRING_ARG",
"server_infra_host_ttl : VAR_INFRA_HOST_TTL STRING_ARG",
"server_infra_lame_ttl : VAR_INFRA_LAME_TTL STRING_ARG",
"server_infra_cache_numhosts : VAR_INFRA_CACHE_NUMHOSTS STRING_ARG",
"server_infra_cache_lame_size : VAR_INFRA_CACHE_LAME_SIZE STRING_ARG",
"server_infra_cache_slabs : VAR_INFRA_CACHE_SLABS STRING_ARG",
"server_infra_cache_min_rtt : VAR_INFRA_CACHE_MIN_RTT STRING_ARG",
"server_target_fetch_policy : VAR_TARGET_FETCH_POLICY STRING_ARG",
"server_harden_short_bufsize : VAR_HARDEN_SHORT_BUFSIZE STRING_ARG",
"server_harden_large_queries : VAR_HARDEN_LARGE_QUERIES STRING_ARG",
"server_harden_glue : VAR_HARDEN_GLUE STRING_ARG",
"server_harden_dnssec_stripped : VAR_HARDEN_DNSSEC_STRIPPED STRING_ARG",
"server_harden_below_nxdomain : VAR_HARDEN_BELOW_NXDOMAIN STRING_ARG",
"server_harden_referral_path : VAR_HARDEN_REFERRAL_PATH STRING_ARG",
"server_harden_algo_downgrade : VAR_HARDEN_ALGO_DOWNGRADE STRING_ARG",
"server_use_caps_for_id : VAR_USE_CAPS_FOR_ID STRING_ARG",
"server_caps_whitelist : VAR_CAPS_WHITELIST STRING_ARG",
"server_private_address : VAR_PRIVATE_ADDRESS STRING_ARG",
"server_private_domain : VAR_PRIVATE_DOMAIN STRING_ARG",
"server_prefetch : VAR_PREFETCH STRING_ARG",
"server_prefetch_key : VAR_PREFETCH_KEY STRING_ARG",
"server_unwanted_reply_threshold : VAR_UNWANTED_REPLY_THRESHOLD STRING_ARG",
"server_do_not_query_address : VAR_DO_NOT_QUERY_ADDRESS STRING_ARG",
"server_do_not_query_localhost : VAR_DO_NOT_QUERY_LOCALHOST STRING_ARG",
"server_access_control : VAR_ACCESS_CONTROL STRING_ARG STRING_ARG",
"server_module_conf : VAR_MODULE_CONF STRING_ARG",
"server_val_override_date : VAR_VAL_OVERRIDE_DATE STRING_ARG",
"server_val_sig_skew_min : VAR_VAL_SIG_SKEW_MIN STRING_ARG",
"server_val_sig_skew_max : VAR_VAL_SIG_SKEW_MAX STRING_ARG",
"server_cache_max_ttl : VAR_CACHE_MAX_TTL STRING_ARG",
"server_cache_max_negative_ttl : VAR_CACHE_MAX_NEGATIVE_TTL STRING_ARG",
"server_cache_min_ttl : VAR_CACHE_MIN_TTL STRING_ARG",
"server_bogus_ttl : VAR_BOGUS_TTL STRING_ARG",
"server_val_clean_additional : VAR_VAL_CLEAN_ADDITIONAL STRING_ARG",
"server_val_permissive_mode : VAR_VAL_PERMISSIVE_MODE STRING_ARG",
"server_aggressive_nsec : VAR_AGGRESSIVE_NSEC STRING_ARG",
"server_ignore_cd_flag : VAR_IGNORE_CD_FLAG STRING_ARG",
"server_serve_expired : VAR_SERVE_EXPIRED STRING_ARG",
"server_fake_dsa : VAR_FAKE_DSA STRING_ARG",
"server_fake_sha1 : VAR_FAKE_SHA1 STRING_ARG",
"server_val_log_level : VAR_VAL_LOG_LEVEL STRING_ARG",
"server_val_nsec3_keysize_iterations : VAR_VAL_NSEC3_KEYSIZE_ITERATIONS STRING_ARG",
"server_add_holddown : VAR_ADD_HOLDDOWN STRING_ARG",
"server_del_holddown : VAR_DEL_HOLDDOWN STRING_ARG",
"server_keep_missing : VAR_KEEP_MISSING STRING_ARG",
"server_permit_small_holddown : VAR_PERMIT_SMALL_HOLDDOWN STRING_ARG",
"server_key_cache_size : VAR_KEY_CACHE_SIZE STRING_ARG",
"server_key_cache_slabs : VAR_KEY_CACHE_SLABS STRING_ARG",
"server_neg_cache_size : VAR_NEG_CACHE_SIZE STRING_ARG",
"server_local_zone : VAR_LOCAL_ZONE STRING_ARG STRING_ARG",
"server_local_data : VAR_LOCAL_DATA STRING_ARG",
"server_local_data_ptr : VAR_LOCAL_DATA_PTR STRING_ARG",
"server_minimal_responses : VAR_MINIMAL_RESPONSES STRING_ARG",
"server_rrset_roundrobin : VAR_RRSET_ROUNDROBIN STRING_ARG",
"server_max_udp_size : VAR_MAX_UDP_SIZE STRING_ARG",
"server_dns64_prefix : VAR_DNS64_PREFIX STRING_ARG",
"server_dns64_synthall : VAR_DNS64_SYNTHALL STRING_ARG",
"server_define_tag : VAR_DEFINE_TAG STRING_ARG",
"server_local_zone_tag : VAR_LOCAL_ZONE_TAG STRING_ARG STRING_ARG",
"server_access_control_tag : VAR_ACCESS_CONTROL_TAG STRING_ARG STRING_ARG",
"server_access_control_tag_action : VAR_ACCESS_CONTROL_TAG_ACTION STRING_ARG STRING_ARG STRING_ARG",
"server_access_control_tag_data : VAR_ACCESS_CONTROL_TAG_DATA STRING_ARG STRING_ARG STRING_ARG",
"server_local_zone_override : VAR_LOCAL_ZONE_OVERRIDE STRING_ARG STRING_ARG STRING_ARG",
"server_access_control_view : VAR_ACCESS_CONTROL_VIEW STRING_ARG STRING_ARG",
"server_response_ip_tag : VAR_RESPONSE_IP_TAG STRING_ARG STRING_ARG",
"server_ip_ratelimit : VAR_IP_RATELIMIT STRING_ARG",
"server_ratelimit : VAR_RATELIMIT STRING_ARG",
"server_ip_ratelimit_size : VAR_IP_RATELIMIT_SIZE STRING_ARG",
"server_ratelimit_size : VAR_RATELIMIT_SIZE STRING_ARG",
"server_ip_ratelimit_slabs : VAR_IP_RATELIMIT_SLABS STRING_ARG",
"server_ratelimit_slabs : VAR_RATELIMIT_SLABS STRING_ARG",
"server_ratelimit_for_domain : VAR_RATELIMIT_FOR_DOMAIN STRING_ARG STRING_ARG",
"server_ratelimit_below_domain : VAR_RATELIMIT_BELOW_DOMAIN STRING_ARG STRING_ARG",
"server_ip_ratelimit_factor : VAR_IP_RATELIMIT_FACTOR STRING_ARG",
"server_ratelimit_factor : VAR_RATELIMIT_FACTOR STRING_ARG",
"server_qname_minimisation : VAR_QNAME_MINIMISATION STRING_ARG",
"server_qname_minimisation_strict : VAR_QNAME_MINIMISATION_STRICT STRING_ARG",
"server_ipsecmod_enabled : VAR_IPSECMOD_ENABLED STRING_ARG",
"server_ipsecmod_ignore_bogus : VAR_IPSECMOD_IGNORE_BOGUS STRING_ARG",
"server_ipsecmod_hook : VAR_IPSECMOD_HOOK STRING_ARG",
"server_ipsecmod_max_ttl : VAR_IPSECMOD_MAX_TTL STRING_ARG",
"server_ipsecmod_whitelist : VAR_IPSECMOD_WHITELIST STRING_ARG",
"server_ipsecmod_strict : VAR_IPSECMOD_STRICT STRING_ARG",
"stub_name : VAR_NAME STRING_ARG",
"stub_host : VAR_STUB_HOST STRING_ARG",
"stub_addr : VAR_STUB_ADDR STRING_ARG",
"stub_first : VAR_STUB_FIRST STRING_ARG",
"stub_ssl_upstream : VAR_STUB_SSL_UPSTREAM STRING_ARG",
"stub_prime : VAR_STUB_PRIME STRING_ARG",
"forward_name : VAR_NAME STRING_ARG",
"forward_host : VAR_FORWARD_HOST STRING_ARG",
"forward_addr : VAR_FORWARD_ADDR STRING_ARG",
"forward_first : VAR_FORWARD_FIRST STRING_ARG",
"forward_preference : VAR_FORWARD_PREFERENCE STRING_ARG",
"forward_ssl_upstream : VAR_FORWARD_SSL_UPSTREAM STRING_ARG",
"auth_name : VAR_NAME STRING_ARG",
"auth_zonefile : VAR_ZONEFILE STRING_ARG",
"auth_master : VAR_MASTER STRING_ARG",
"auth_url : VAR_URL STRING_ARG",
"auth_for_downstream : VAR_FOR_DOWNSTREAM STRING_ARG",
"auth_for_upstream : VAR_FOR_UPSTREAM STRING_ARG",
"auth_fallback_enabled : VAR_FALLBACK_ENABLED STRING_ARG",
"view_name : VAR_NAME STRING_ARG",
"view_local_zone : VAR_LOCAL_ZONE STRING_ARG STRING_ARG",
"view_response_ip : VAR_RESPONSE_IP STRING_ARG STRING_ARG",
"view_response_ip_data : VAR_RESPONSE_IP_DATA STRING_ARG STRING_ARG",
"view_local_data : VAR_LOCAL_DATA STRING_ARG",
"view_local_data_ptr : VAR_LOCAL_DATA_PTR STRING_ARG",
"view_first : VAR_VIEW_FIRST STRING_ARG",
"rcstart : VAR_REMOTE_CONTROL",
"contents_rc : contents_rc content_rc",
"contents_rc :",
"content_rc : rc_control_enable",
"content_rc : rc_control_interface",
"content_rc : rc_control_port",
"content_rc : rc_server_key_file",
"content_rc : rc_server_cert_file",
"content_rc : rc_control_key_file",
"content_rc : rc_control_cert_file",
"content_rc : rc_control_use_cert",
"rc_control_enable : VAR_CONTROL_ENABLE STRING_ARG",
"rc_control_port : VAR_CONTROL_PORT STRING_ARG",
"rc_control_interface : VAR_CONTROL_INTERFACE STRING_ARG",
"rc_control_use_cert : VAR_CONTROL_USE_CERT STRING_ARG",
"rc_server_key_file : VAR_SERVER_KEY_FILE STRING_ARG",
"rc_server_cert_file : VAR_SERVER_CERT_FILE STRING_ARG",
"rc_control_key_file : VAR_CONTROL_KEY_FILE STRING_ARG",
"rc_control_cert_file : VAR_CONTROL_CERT_FILE STRING_ARG",
"dtstart : VAR_DNSTAP",
"contents_dt : contents_dt content_dt",
"contents_dt :",
"content_dt : dt_dnstap_enable",
"content_dt : dt_dnstap_socket_path",
"content_dt : dt_dnstap_send_identity",
"content_dt : dt_dnstap_send_version",
"content_dt : dt_dnstap_identity",
"content_dt : dt_dnstap_version",
"content_dt : dt_dnstap_log_resolver_query_messages",
"content_dt : dt_dnstap_log_resolver_response_messages",
"content_dt : dt_dnstap_log_client_query_messages",
"content_dt : dt_dnstap_log_client_response_messages",
"content_dt : dt_dnstap_log_forwarder_query_messages",
"content_dt : dt_dnstap_log_forwarder_response_messages",
"dt_dnstap_enable : VAR_DNSTAP_ENABLE STRING_ARG",
"dt_dnstap_socket_path : VAR_DNSTAP_SOCKET_PATH STRING_ARG",
"dt_dnstap_send_identity : VAR_DNSTAP_SEND_IDENTITY STRING_ARG",
"dt_dnstap_send_version : VAR_DNSTAP_SEND_VERSION STRING_ARG",
"dt_dnstap_identity : VAR_DNSTAP_IDENTITY STRING_ARG",
"dt_dnstap_version : VAR_DNSTAP_VERSION STRING_ARG",
"dt_dnstap_log_resolver_query_messages : VAR_DNSTAP_LOG_RESOLVER_QUERY_MESSAGES STRING_ARG",
"dt_dnstap_log_resolver_response_messages : VAR_DNSTAP_LOG_RESOLVER_RESPONSE_MESSAGES STRING_ARG",
"dt_dnstap_log_client_query_messages : VAR_DNSTAP_LOG_CLIENT_QUERY_MESSAGES STRING_ARG",
"dt_dnstap_log_client_response_messages : VAR_DNSTAP_LOG_CLIENT_RESPONSE_MESSAGES STRING_ARG",
"dt_dnstap_log_forwarder_query_messages : VAR_DNSTAP_LOG_FORWARDER_QUERY_MESSAGES STRING_ARG",
"dt_dnstap_log_forwarder_response_messages : VAR_DNSTAP_LOG_FORWARDER_RESPONSE_MESSAGES STRING_ARG",
"pythonstart : VAR_PYTHON",
"contents_py : contents_py content_py",
"contents_py :",
"content_py : py_script",
"py_script : VAR_PYTHON_SCRIPT STRING_ARG",
"server_disable_dnssec_lame_check : VAR_DISABLE_DNSSEC_LAME_CHECK STRING_ARG",
"server_log_identity : VAR_LOG_IDENTITY STRING_ARG",
"server_response_ip : VAR_RESPONSE_IP STRING_ARG STRING_ARG",
"server_response_ip_data : VAR_RESPONSE_IP_DATA STRING_ARG STRING_ARG",
"dnscstart : VAR_DNSCRYPT",
"contents_dnsc : contents_dnsc content_dnsc",
"contents_dnsc :",
"content_dnsc : dnsc_dnscrypt_enable",
"content_dnsc : dnsc_dnscrypt_port",
"content_dnsc : dnsc_dnscrypt_provider",
"content_dnsc : dnsc_dnscrypt_secret_key",
"content_dnsc : dnsc_dnscrypt_provider_cert",
"content_dnsc : dnsc_dnscrypt_provider_cert_rotated",
"content_dnsc : dnsc_dnscrypt_shared_secret_cache_size",
"content_dnsc : dnsc_dnscrypt_shared_secret_cache_slabs",
"content_dnsc : dnsc_dnscrypt_nonce_cache_size",
"content_dnsc : dnsc_dnscrypt_nonce_cache_slabs",
"dnsc_dnscrypt_enable : VAR_DNSCRYPT_ENABLE STRING_ARG",
"dnsc_dnscrypt_port : VAR_DNSCRYPT_PORT STRING_ARG",
"dnsc_dnscrypt_provider : VAR_DNSCRYPT_PROVIDER STRING_ARG",
"dnsc_dnscrypt_provider_cert : VAR_DNSCRYPT_PROVIDER_CERT STRING_ARG",
"dnsc_dnscrypt_provider_cert_rotated : VAR_DNSCRYPT_PROVIDER_CERT_ROTATED STRING_ARG",
"dnsc_dnscrypt_secret_key : VAR_DNSCRYPT_SECRET_KEY STRING_ARG",
"dnsc_dnscrypt_shared_secret_cache_size : VAR_DNSCRYPT_SHARED_SECRET_CACHE_SIZE STRING_ARG",
"dnsc_dnscrypt_shared_secret_cache_slabs : VAR_DNSCRYPT_SHARED_SECRET_CACHE_SLABS STRING_ARG",
"dnsc_dnscrypt_nonce_cache_size : VAR_DNSCRYPT_NONCE_CACHE_SIZE STRING_ARG",
"dnsc_dnscrypt_nonce_cache_slabs : VAR_DNSCRYPT_NONCE_CACHE_SLABS STRING_ARG",
"cachedbstart : VAR_CACHEDB",
"contents_cachedb : contents_cachedb content_cachedb",
"contents_cachedb :",
"content_cachedb : cachedb_backend_name",
"content_cachedb : cachedb_secret_seed",
"cachedb_backend_name : VAR_CACHEDB_BACKEND STRING_ARG",
"cachedb_secret_seed : VAR_CACHEDB_SECRETSEED STRING_ARG",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 2600 "./util/configparser.y"

/* parse helper routines could be here */
static void
validate_respip_action(const char* action)
{
	if(strcmp(action, "deny")!=0 &&
		strcmp(action, "redirect")!=0 &&
		strcmp(action, "inform")!=0 &&
		strcmp(action, "inform_deny")!=0 &&
		strcmp(action, "always_transparent")!=0 &&
		strcmp(action, "always_refuse")!=0 &&
		strcmp(action, "always_nxdomain")!=0)
	{
		yyerror("response-ip action: expected deny, redirect, "
			"inform, inform_deny, always_transparent, "
			"always_refuse or always_nxdomain");
	}
}
#line 1513 "util/configparser.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 13:
#line 171 "./util/configparser.y"
	{ 
		OUTYY(("\nP(server:)\n")); 
	}
break;
case 179:
#line 251 "./util/configparser.y"
	{
		struct config_stub* s;
		OUTYY(("\nP(stub_zone:)\n")); 
		s = (struct config_stub*)calloc(1, sizeof(struct config_stub));
		if(s) {
			s->next = cfg_parser->cfg->stubs;
			cfg_parser->cfg->stubs = s;
		} else 
			yyerror("out of memory");
	}
break;
case 188:
#line 268 "./util/configparser.y"
	{
		struct config_stub* s;
		OUTYY(("\nP(forward_zone:)\n")); 
		s = (struct config_stub*)calloc(1, sizeof(struct config_stub));
		if(s) {
			s->next = cfg_parser->cfg->forwards;
			cfg_parser->cfg->forwards = s;
		} else 
			yyerror("out of memory");
	}
break;
case 196:
#line 285 "./util/configparser.y"
	{
		struct config_view* s;
		OUTYY(("\nP(view:)\n")); 
		s = (struct config_view*)calloc(1, sizeof(struct config_view));
		if(s) {
			s->next = cfg_parser->cfg->views;
			if(s->next && !s->next->name)
				yyerror("view without name");
			cfg_parser->cfg->views = s;
		} else 
			yyerror("out of memory");
	}
break;
case 206:
#line 304 "./util/configparser.y"
	{
		struct config_auth* s;
		OUTYY(("\nP(auth_zone:)\n")); 
		s = (struct config_auth*)calloc(1, sizeof(struct config_auth));
		if(s) {
			s->next = cfg_parser->cfg->auths;
			cfg_parser->cfg->auths = s;
			/* defaults for auth zone */
			s->for_downstream = 1;
			s->for_upstream = 1;
			s->fallback_enabled = 0;
		} else 
			yyerror("out of memory");
	}
break;
case 216:
#line 325 "./util/configparser.y"
	{ 
		OUTYY(("P(server_num_threads:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->num_threads = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 217:
#line 334 "./util/configparser.y"
	{ 
		OUTYY(("P(server_verbosity:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->verbosity = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 218:
#line 343 "./util/configparser.y"
	{ 
		OUTYY(("P(server_statistics_interval:%s)\n", yystack.l_mark[0].str)); 
		if(strcmp(yystack.l_mark[0].str, "") == 0 || strcmp(yystack.l_mark[0].str, "0") == 0)
			cfg_parser->cfg->stat_interval = 0;
		else if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->stat_interval = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 219:
#line 354 "./util/configparser.y"
	{
		OUTYY(("P(server_statistics_cumulative:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stat_cumulative = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 220:
#line 363 "./util/configparser.y"
	{
		OUTYY(("P(server_extended_statistics:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stat_extended = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 221:
#line 372 "./util/configparser.y"
	{
		OUTYY(("P(server_shm_enable:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->shm_enable = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 222:
#line 381 "./util/configparser.y"
	{ 
		OUTYY(("P(server_shm_key:%s)\n", yystack.l_mark[0].str)); 
		if(strcmp(yystack.l_mark[0].str, "") == 0 || strcmp(yystack.l_mark[0].str, "0") == 0)
			cfg_parser->cfg->shm_key = 0;
		else if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->shm_key = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 223:
#line 392 "./util/configparser.y"
	{
		OUTYY(("P(server_port:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("port number expected");
		else cfg_parser->cfg->port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 224:
#line 401 "./util/configparser.y"
	{
	#ifdef CLIENT_SUBNET
		OUTYY(("P(server_send_client_subnet:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->client_subnet, yystack.l_mark[0].str))
			fatal_exit("out of memory adding client-subnet");
	#else
		OUTYY(("P(Compiled without edns subnet option, ignoring)\n"));
	#endif
	}
break;
case 225:
#line 412 "./util/configparser.y"
	{
	#ifdef CLIENT_SUBNET
		OUTYY(("P(server_client_subnet_zone:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->client_subnet_zone,
			yystack.l_mark[0].str))
			fatal_exit("out of memory adding client-subnet-zone");
	#else
		OUTYY(("P(Compiled without edns subnet option, ignoring)\n"));
	#endif
	}
break;
case 226:
#line 425 "./util/configparser.y"
	{
	#ifdef CLIENT_SUBNET
		OUTYY(("P(server_client_subnet_always_forward:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else
			cfg_parser->cfg->client_subnet_always_forward =
				(strcmp(yystack.l_mark[0].str, "yes")==0);
	#else
		OUTYY(("P(Compiled without edns subnet option, ignoring)\n"));
	#endif
		free(yystack.l_mark[0].str);
	}
break;
case 227:
#line 440 "./util/configparser.y"
	{
	#ifdef CLIENT_SUBNET
		OUTYY(("P(client_subnet_opcode:%s)\n", yystack.l_mark[0].str));
		OUTYY(("P(Deprecated option, ignoring)\n"));
	#else
		OUTYY(("P(Compiled without edns subnet option, ignoring)\n"));
	#endif
		free(yystack.l_mark[0].str);
	}
break;
case 228:
#line 451 "./util/configparser.y"
	{
	#ifdef CLIENT_SUBNET
		OUTYY(("P(max_client_subnet_ipv4:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("IPv4 subnet length expected");
		else if (atoi(yystack.l_mark[0].str) > 32)
			cfg_parser->cfg->max_client_subnet_ipv4 = 32;
		else if (atoi(yystack.l_mark[0].str) < 0)
			cfg_parser->cfg->max_client_subnet_ipv4 = 0;
		else cfg_parser->cfg->max_client_subnet_ipv4 = (uint8_t)atoi(yystack.l_mark[0].str);
	#else
		OUTYY(("P(Compiled without edns subnet option, ignoring)\n"));
	#endif
		free(yystack.l_mark[0].str);
	}
break;
case 229:
#line 468 "./util/configparser.y"
	{
	#ifdef CLIENT_SUBNET
		OUTYY(("P(max_client_subnet_ipv6:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("Ipv6 subnet length expected");
		else if (atoi(yystack.l_mark[0].str) > 128)
			cfg_parser->cfg->max_client_subnet_ipv6 = 128;
		else if (atoi(yystack.l_mark[0].str) < 0)
			cfg_parser->cfg->max_client_subnet_ipv6 = 0;
		else cfg_parser->cfg->max_client_subnet_ipv6 = (uint8_t)atoi(yystack.l_mark[0].str);
	#else
		OUTYY(("P(Compiled without edns subnet option, ignoring)\n"));
	#endif
		free(yystack.l_mark[0].str);
	}
break;
case 230:
#line 485 "./util/configparser.y"
	{
		OUTYY(("P(server_interface:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->num_ifs == 0)
			cfg_parser->cfg->ifs = calloc(1, sizeof(char*));
		else 	cfg_parser->cfg->ifs = realloc(cfg_parser->cfg->ifs,
				(cfg_parser->cfg->num_ifs+1)*sizeof(char*));
		if(!cfg_parser->cfg->ifs)
			yyerror("out of memory");
		else
			cfg_parser->cfg->ifs[cfg_parser->cfg->num_ifs++] = yystack.l_mark[0].str;
	}
break;
case 231:
#line 498 "./util/configparser.y"
	{
		OUTYY(("P(server_outgoing_interface:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->num_out_ifs == 0)
			cfg_parser->cfg->out_ifs = calloc(1, sizeof(char*));
		else 	cfg_parser->cfg->out_ifs = realloc(
			cfg_parser->cfg->out_ifs, 
			(cfg_parser->cfg->num_out_ifs+1)*sizeof(char*));
		if(!cfg_parser->cfg->out_ifs)
			yyerror("out of memory");
		else
			cfg_parser->cfg->out_ifs[
				cfg_parser->cfg->num_out_ifs++] = yystack.l_mark[0].str;
	}
break;
case 232:
#line 513 "./util/configparser.y"
	{
		OUTYY(("P(server_outgoing_range:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->outgoing_num_ports = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 233:
#line 522 "./util/configparser.y"
	{
		OUTYY(("P(server_outgoing_port_permit:%s)\n", yystack.l_mark[0].str));
		if(!cfg_mark_ports(yystack.l_mark[0].str, 1, 
			cfg_parser->cfg->outgoing_avail_ports, 65536))
			yyerror("port number or range (\"low-high\") expected");
		free(yystack.l_mark[0].str);
	}
break;
case 234:
#line 531 "./util/configparser.y"
	{
		OUTYY(("P(server_outgoing_port_avoid:%s)\n", yystack.l_mark[0].str));
		if(!cfg_mark_ports(yystack.l_mark[0].str, 0, 
			cfg_parser->cfg->outgoing_avail_ports, 65536))
			yyerror("port number or range (\"low-high\") expected");
		free(yystack.l_mark[0].str);
	}
break;
case 235:
#line 540 "./util/configparser.y"
	{
		OUTYY(("P(server_outgoing_num_tcp:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->outgoing_num_tcp = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 236:
#line 549 "./util/configparser.y"
	{
		OUTYY(("P(server_incoming_num_tcp:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->incoming_num_tcp = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 237:
#line 558 "./util/configparser.y"
	{
		OUTYY(("P(server_interface_automatic:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->if_automatic = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 238:
#line 567 "./util/configparser.y"
	{
		OUTYY(("P(server_do_ip4:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_ip4 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 239:
#line 576 "./util/configparser.y"
	{
		OUTYY(("P(server_do_ip6:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_ip6 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 240:
#line 585 "./util/configparser.y"
	{
		OUTYY(("P(server_do_udp:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_udp = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 241:
#line 594 "./util/configparser.y"
	{
		OUTYY(("P(server_do_tcp:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_tcp = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 242:
#line 603 "./util/configparser.y"
	{
		OUTYY(("P(server_prefer_ip6:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->prefer_ip6 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 243:
#line 612 "./util/configparser.y"
	{
		OUTYY(("P(server_tcp_mss:%s)\n", yystack.l_mark[0].str));
                if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
                        yyerror("number expected");
                else cfg_parser->cfg->tcp_mss = atoi(yystack.l_mark[0].str);
                free(yystack.l_mark[0].str);
	}
break;
case 244:
#line 621 "./util/configparser.y"
	{
		OUTYY(("P(server_outgoing_tcp_mss:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->outgoing_tcp_mss = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 245:
#line 630 "./util/configparser.y"
	{
		OUTYY(("P(server_tcp_upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->tcp_upstream = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 246:
#line 639 "./util/configparser.y"
	{
		OUTYY(("P(server_udp_upstream_without_downstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->udp_upstream_without_downstream = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 247:
#line 648 "./util/configparser.y"
	{
		OUTYY(("P(server_ssl_upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ssl_upstream = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 248:
#line 657 "./util/configparser.y"
	{
		OUTYY(("P(server_ssl_service_key:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->ssl_service_key);
		cfg_parser->cfg->ssl_service_key = yystack.l_mark[0].str;
	}
break;
case 249:
#line 664 "./util/configparser.y"
	{
		OUTYY(("P(server_ssl_service_pem:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->ssl_service_pem);
		cfg_parser->cfg->ssl_service_pem = yystack.l_mark[0].str;
	}
break;
case 250:
#line 671 "./util/configparser.y"
	{
		OUTYY(("P(server_ssl_port:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("port number expected");
		else cfg_parser->cfg->ssl_port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 251:
#line 680 "./util/configparser.y"
	{
		OUTYY(("P(server_tls_cert_bundle:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->tls_cert_bundle);
		cfg_parser->cfg->tls_cert_bundle = yystack.l_mark[0].str;
	}
break;
case 252:
#line 687 "./util/configparser.y"
	{
		OUTYY(("P(server_use_systemd:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->use_systemd = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 253:
#line 696 "./util/configparser.y"
	{
		OUTYY(("P(server_do_daemonize:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_daemonize = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 254:
#line 705 "./util/configparser.y"
	{
		OUTYY(("P(server_use_syslog:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->use_syslog = (strcmp(yystack.l_mark[0].str, "yes")==0);
#if !defined(HAVE_SYSLOG_H) && !defined(UB_ON_WINDOWS)
		if(strcmp(yystack.l_mark[0].str, "yes") == 0)
			yyerror("no syslog services are available. "
				"(reconfigure and compile to add)");
#endif
		free(yystack.l_mark[0].str);
	}
break;
case 255:
#line 719 "./util/configparser.y"
	{
		OUTYY(("P(server_log_time_ascii:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->log_time_ascii = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 256:
#line 728 "./util/configparser.y"
	{
		OUTYY(("P(server_log_queries:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->log_queries = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 257:
#line 737 "./util/configparser.y"
	{
  	OUTYY(("P(server_log_replies:%s)\n", yystack.l_mark[0].str));
  	if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
  		yyerror("expected yes or no.");
  	else cfg_parser->cfg->log_replies = (strcmp(yystack.l_mark[0].str, "yes")==0);
  	free(yystack.l_mark[0].str);
  }
break;
case 258:
#line 746 "./util/configparser.y"
	{
		OUTYY(("P(server_chroot:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->chrootdir);
		cfg_parser->cfg->chrootdir = yystack.l_mark[0].str;
	}
break;
case 259:
#line 753 "./util/configparser.y"
	{
		OUTYY(("P(server_username:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->username);
		cfg_parser->cfg->username = yystack.l_mark[0].str;
	}
break;
case 260:
#line 760 "./util/configparser.y"
	{
		OUTYY(("P(server_directory:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->directory);
		cfg_parser->cfg->directory = yystack.l_mark[0].str;
		/* change there right away for includes relative to this */
		if(yystack.l_mark[0].str[0]) {
			char* d;
#ifdef UB_ON_WINDOWS
			w_config_adjust_directory(cfg_parser->cfg);
#endif
			d = cfg_parser->cfg->directory;
			/* adjust directory if we have already chroot,
			 * like, we reread after sighup */
			if(cfg_parser->chroot && cfg_parser->chroot[0] &&
				strncmp(d, cfg_parser->chroot, strlen(
				cfg_parser->chroot)) == 0)
				d += strlen(cfg_parser->chroot);
			if(d[0]) {
			    if(chdir(d))
				log_err("cannot chdir to directory: %s (%s)",
					d, strerror(errno));
			}
		}
	}
break;
case 261:
#line 786 "./util/configparser.y"
	{
		OUTYY(("P(server_logfile:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->logfile);
		cfg_parser->cfg->logfile = yystack.l_mark[0].str;
		cfg_parser->cfg->use_syslog = 0;
	}
break;
case 262:
#line 794 "./util/configparser.y"
	{
		OUTYY(("P(server_pidfile:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->pidfile);
		cfg_parser->cfg->pidfile = yystack.l_mark[0].str;
	}
break;
case 263:
#line 801 "./util/configparser.y"
	{
		OUTYY(("P(server_root_hints:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->root_hints, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 264:
#line 808 "./util/configparser.y"
	{
		OUTYY(("P(server_dlv_anchor_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dlv_anchor_file);
		cfg_parser->cfg->dlv_anchor_file = yystack.l_mark[0].str;
	}
break;
case 265:
#line 815 "./util/configparser.y"
	{
		OUTYY(("P(server_dlv_anchor:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->dlv_anchor_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 266:
#line 822 "./util/configparser.y"
	{
		OUTYY(("P(server_auto_trust_anchor_file:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->
			auto_trust_anchor_file_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 267:
#line 830 "./util/configparser.y"
	{
		OUTYY(("P(server_trust_anchor_file:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->
			trust_anchor_file_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 268:
#line 838 "./util/configparser.y"
	{
		OUTYY(("P(server_trusted_keys_file:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->
			trusted_keys_file_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 269:
#line 846 "./util/configparser.y"
	{
		OUTYY(("P(server_trust_anchor:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->trust_anchor_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 270:
#line 853 "./util/configparser.y"
	{
		OUTYY(("P(server_trust_anchor_signaling:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else
			cfg_parser->cfg->trust_anchor_signaling =
				(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 271:
#line 864 "./util/configparser.y"
	{
		OUTYY(("P(server_domain_insecure:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->domain_insecure, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 272:
#line 871 "./util/configparser.y"
	{
		OUTYY(("P(server_hide_identity:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->hide_identity = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 273:
#line 880 "./util/configparser.y"
	{
		OUTYY(("P(server_hide_version:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->hide_version = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 274:
#line 889 "./util/configparser.y"
	{
		OUTYY(("P(server_hide_trustanchor:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->hide_trustanchor = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 275:
#line 898 "./util/configparser.y"
	{
		OUTYY(("P(server_identity:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->identity);
		cfg_parser->cfg->identity = yystack.l_mark[0].str;
	}
break;
case 276:
#line 905 "./util/configparser.y"
	{
		OUTYY(("P(server_version:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->version);
		cfg_parser->cfg->version = yystack.l_mark[0].str;
	}
break;
case 277:
#line 912 "./util/configparser.y"
	{
		OUTYY(("P(server_so_rcvbuf:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->so_rcvbuf))
			yyerror("buffer size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 278:
#line 920 "./util/configparser.y"
	{
		OUTYY(("P(server_so_sndbuf:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->so_sndbuf))
			yyerror("buffer size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 279:
#line 928 "./util/configparser.y"
	{
        OUTYY(("P(server_so_reuseport:%s)\n", yystack.l_mark[0].str));
        if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
            yyerror("expected yes or no.");
        else cfg_parser->cfg->so_reuseport =
            (strcmp(yystack.l_mark[0].str, "yes")==0);
        free(yystack.l_mark[0].str);
    }
break;
case 280:
#line 938 "./util/configparser.y"
	{
        OUTYY(("P(server_ip_transparent:%s)\n", yystack.l_mark[0].str));
        if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
            yyerror("expected yes or no.");
        else cfg_parser->cfg->ip_transparent =
            (strcmp(yystack.l_mark[0].str, "yes")==0);
        free(yystack.l_mark[0].str);
    }
break;
case 281:
#line 948 "./util/configparser.y"
	{
        OUTYY(("P(server_ip_freebind:%s)\n", yystack.l_mark[0].str));
        if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
            yyerror("expected yes or no.");
        else cfg_parser->cfg->ip_freebind =
            (strcmp(yystack.l_mark[0].str, "yes")==0);
        free(yystack.l_mark[0].str);
    }
break;
case 282:
#line 958 "./util/configparser.y"
	{
		OUTYY(("P(server_edns_buffer_size:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else if (atoi(yystack.l_mark[0].str) < 12)
			yyerror("edns buffer size too small");
		else if (atoi(yystack.l_mark[0].str) > 65535)
			cfg_parser->cfg->edns_buffer_size = 65535;
		else cfg_parser->cfg->edns_buffer_size = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 283:
#line 971 "./util/configparser.y"
	{
		OUTYY(("P(server_msg_buffer_size:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else if (atoi(yystack.l_mark[0].str) < 4096)
			yyerror("message buffer size too small (use 4096)");
		else cfg_parser->cfg->msg_buffer_size = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 284:
#line 982 "./util/configparser.y"
	{
		OUTYY(("P(server_msg_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->msg_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 285:
#line 990 "./util/configparser.y"
	{
		OUTYY(("P(server_msg_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->msg_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->msg_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 286:
#line 1003 "./util/configparser.y"
	{
		OUTYY(("P(server_num_queries_per_thread:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->num_queries_per_thread = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 287:
#line 1012 "./util/configparser.y"
	{
		OUTYY(("P(server_jostle_timeout:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->jostle_time = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 288:
#line 1021 "./util/configparser.y"
	{
		OUTYY(("P(server_delay_close:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->delay_close = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 289:
#line 1030 "./util/configparser.y"
	{
		OUTYY(("P(server_unblock_lan_zones:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->unblock_lan_zones = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 290:
#line 1040 "./util/configparser.y"
	{
		OUTYY(("P(server_insecure_lan_zones:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->insecure_lan_zones = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 291:
#line 1050 "./util/configparser.y"
	{
		OUTYY(("P(server_rrset_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->rrset_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 292:
#line 1058 "./util/configparser.y"
	{
		OUTYY(("P(server_rrset_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->rrset_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->rrset_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 293:
#line 1071 "./util/configparser.y"
	{
		OUTYY(("P(server_infra_host_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->host_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 294:
#line 1080 "./util/configparser.y"
	{
		OUTYY(("P(server_infra_lame_ttl:%s)\n", yystack.l_mark[0].str));
		verbose(VERB_DETAIL, "ignored infra-lame-ttl: %s (option "
			"removed, use infra-host-ttl)", yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 295:
#line 1088 "./util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_numhosts:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->infra_cache_numhosts = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 296:
#line 1097 "./util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_lame_size:%s)\n", yystack.l_mark[0].str));
		verbose(VERB_DETAIL, "ignored infra-cache-lame-size: %s "
			"(option removed, use infra-cache-numhosts)", yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 297:
#line 1105 "./util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->infra_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->infra_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 298:
#line 1118 "./util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_min_rtt:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->infra_cache_min_rtt = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 299:
#line 1127 "./util/configparser.y"
	{
		OUTYY(("P(server_target_fetch_policy:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->target_fetch_policy);
		cfg_parser->cfg->target_fetch_policy = yystack.l_mark[0].str;
	}
break;
case 300:
#line 1134 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_short_bufsize:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_short_bufsize = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 301:
#line 1144 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_large_queries:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_large_queries = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 302:
#line 1154 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_glue:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_glue = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 303:
#line 1164 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_dnssec_stripped:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_dnssec_stripped = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 304:
#line 1174 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_below_nxdomain:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_below_nxdomain = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 305:
#line 1184 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_referral_path:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_referral_path = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 306:
#line 1194 "./util/configparser.y"
	{
		OUTYY(("P(server_harden_algo_downgrade:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_algo_downgrade = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 307:
#line 1204 "./util/configparser.y"
	{
		OUTYY(("P(server_use_caps_for_id:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->use_caps_bits_for_id = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 308:
#line 1214 "./util/configparser.y"
	{
		OUTYY(("P(server_caps_whitelist:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->caps_whitelist, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 309:
#line 1221 "./util/configparser.y"
	{
		OUTYY(("P(server_private_address:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->private_address, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 310:
#line 1228 "./util/configparser.y"
	{
		OUTYY(("P(server_private_domain:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->private_domain, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 311:
#line 1235 "./util/configparser.y"
	{
		OUTYY(("P(server_prefetch:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->prefetch = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 312:
#line 1244 "./util/configparser.y"
	{
		OUTYY(("P(server_prefetch_key:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->prefetch_key = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 313:
#line 1253 "./util/configparser.y"
	{
		OUTYY(("P(server_unwanted_reply_threshold:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->unwanted_threshold = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 314:
#line 1262 "./util/configparser.y"
	{
		OUTYY(("P(server_do_not_query_address:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->donotqueryaddrs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 315:
#line 1269 "./util/configparser.y"
	{
		OUTYY(("P(server_do_not_query_localhost:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->donotquery_localhost = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 316:
#line 1279 "./util/configparser.y"
	{
		OUTYY(("P(server_access_control:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "deny")!=0 && strcmp(yystack.l_mark[0].str, "refuse")!=0 &&
			strcmp(yystack.l_mark[0].str, "deny_non_local")!=0 &&
			strcmp(yystack.l_mark[0].str, "refuse_non_local")!=0 &&
			strcmp(yystack.l_mark[0].str, "allow")!=0 && 
			strcmp(yystack.l_mark[0].str, "allow_snoop")!=0) {
			yyerror("expected deny, refuse, deny_non_local, "
				"refuse_non_local, allow or allow_snoop "
				"in access control action");
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->acls, yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding acl");
		}
	}
break;
case 317:
#line 1296 "./util/configparser.y"
	{
		OUTYY(("P(server_module_conf:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->module_conf);
		cfg_parser->cfg->module_conf = yystack.l_mark[0].str;
	}
break;
case 318:
#line 1303 "./util/configparser.y"
	{
		OUTYY(("P(server_val_override_date:%s)\n", yystack.l_mark[0].str));
		if(*yystack.l_mark[0].str == '\0' || strcmp(yystack.l_mark[0].str, "0") == 0) {
			cfg_parser->cfg->val_date_override = 0;
		} else if(strlen(yystack.l_mark[0].str) == 14) {
			cfg_parser->cfg->val_date_override = 
				cfg_convert_timeval(yystack.l_mark[0].str);
			if(!cfg_parser->cfg->val_date_override)
				yyerror("bad date/time specification");
		} else {
			if(atoi(yystack.l_mark[0].str) == 0)
				yyerror("number expected");
			cfg_parser->cfg->val_date_override = atoi(yystack.l_mark[0].str);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 319:
#line 1321 "./util/configparser.y"
	{
		OUTYY(("P(server_val_sig_skew_min:%s)\n", yystack.l_mark[0].str));
		if(*yystack.l_mark[0].str == '\0' || strcmp(yystack.l_mark[0].str, "0") == 0) {
			cfg_parser->cfg->val_sig_skew_min = 0;
		} else {
			cfg_parser->cfg->val_sig_skew_min = atoi(yystack.l_mark[0].str);
			if(!cfg_parser->cfg->val_sig_skew_min)
				yyerror("number expected");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 320:
#line 1334 "./util/configparser.y"
	{
		OUTYY(("P(server_val_sig_skew_max:%s)\n", yystack.l_mark[0].str));
		if(*yystack.l_mark[0].str == '\0' || strcmp(yystack.l_mark[0].str, "0") == 0) {
			cfg_parser->cfg->val_sig_skew_max = 0;
		} else {
			cfg_parser->cfg->val_sig_skew_max = atoi(yystack.l_mark[0].str);
			if(!cfg_parser->cfg->val_sig_skew_max)
				yyerror("number expected");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 321:
#line 1347 "./util/configparser.y"
	{
		OUTYY(("P(server_cache_max_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->max_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 322:
#line 1356 "./util/configparser.y"
	{
		OUTYY(("P(server_cache_max_negative_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->max_negative_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 323:
#line 1365 "./util/configparser.y"
	{
		OUTYY(("P(server_cache_min_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->min_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 324:
#line 1374 "./util/configparser.y"
	{
		OUTYY(("P(server_bogus_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->bogus_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 325:
#line 1383 "./util/configparser.y"
	{
		OUTYY(("P(server_val_clean_additional:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->val_clean_additional = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 326:
#line 1393 "./util/configparser.y"
	{
		OUTYY(("P(server_val_permissive_mode:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->val_permissive_mode = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 327:
#line 1403 "./util/configparser.y"
	{
		OUTYY(("P(server_aggressive_nsec:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else
			cfg_parser->cfg->aggressive_nsec =
				(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 328:
#line 1414 "./util/configparser.y"
	{
		OUTYY(("P(server_ignore_cd_flag:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ignore_cd = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 329:
#line 1423 "./util/configparser.y"
	{
		OUTYY(("P(server_serve_expired:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->serve_expired = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 330:
#line 1432 "./util/configparser.y"
	{
		OUTYY(("P(server_fake_dsa:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
#ifdef HAVE_SSL
		else fake_dsa = (strcmp(yystack.l_mark[0].str, "yes")==0);
		if(fake_dsa)
			log_warn("test option fake_dsa is enabled");
#endif
		free(yystack.l_mark[0].str);
	}
break;
case 331:
#line 1445 "./util/configparser.y"
	{
		OUTYY(("P(server_fake_sha1:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
#ifdef HAVE_SSL
		else fake_sha1 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		if(fake_sha1)
			log_warn("test option fake_sha1 is enabled");
#endif
		free(yystack.l_mark[0].str);
	}
break;
case 332:
#line 1458 "./util/configparser.y"
	{
		OUTYY(("P(server_val_log_level:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->val_log_level = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 333:
#line 1467 "./util/configparser.y"
	{
		OUTYY(("P(server_val_nsec3_keysize_iterations:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->val_nsec3_key_iterations);
		cfg_parser->cfg->val_nsec3_key_iterations = yystack.l_mark[0].str;
	}
break;
case 334:
#line 1474 "./util/configparser.y"
	{
		OUTYY(("P(server_add_holddown:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->add_holddown = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 335:
#line 1483 "./util/configparser.y"
	{
		OUTYY(("P(server_del_holddown:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->del_holddown = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 336:
#line 1492 "./util/configparser.y"
	{
		OUTYY(("P(server_keep_missing:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->keep_missing = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 337:
#line 1501 "./util/configparser.y"
	{
		OUTYY(("P(server_permit_small_holddown:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->permit_small_holddown =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 338:
#line 1510 "./util/configparser.y"
	{
		OUTYY(("P(server_key_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->key_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 339:
#line 1518 "./util/configparser.y"
	{
		OUTYY(("P(server_key_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->key_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->key_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 340:
#line 1531 "./util/configparser.y"
	{
		OUTYY(("P(server_neg_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->neg_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 341:
#line 1539 "./util/configparser.y"
	{
		OUTYY(("P(server_local_zone:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "static")!=0 && strcmp(yystack.l_mark[0].str, "deny")!=0 &&
		   strcmp(yystack.l_mark[0].str, "refuse")!=0 && strcmp(yystack.l_mark[0].str, "redirect")!=0 &&
		   strcmp(yystack.l_mark[0].str, "transparent")!=0 && strcmp(yystack.l_mark[0].str, "nodefault")!=0
		   && strcmp(yystack.l_mark[0].str, "typetransparent")!=0
		   && strcmp(yystack.l_mark[0].str, "always_transparent")!=0
		   && strcmp(yystack.l_mark[0].str, "always_refuse")!=0
		   && strcmp(yystack.l_mark[0].str, "always_nxdomain")!=0
		   && strcmp(yystack.l_mark[0].str, "inform")!=0 && strcmp(yystack.l_mark[0].str, "inform_deny")!=0)
			yyerror("local-zone type: expected static, deny, "
				"refuse, redirect, transparent, "
				"typetransparent, inform, inform_deny, "
				"always_transparent, always_refuse, "
				"always_nxdomain or nodefault");
		else if(strcmp(yystack.l_mark[0].str, "nodefault")==0) {
			if(!cfg_strlist_insert(&cfg_parser->cfg->
				local_zones_nodefault, yystack.l_mark[-1].str))
				fatal_exit("out of memory adding local-zone");
			free(yystack.l_mark[0].str);
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->local_zones, 
				yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding local-zone");
		}
	}
break;
case 342:
#line 1567 "./util/configparser.y"
	{
		OUTYY(("P(server_local_data:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->local_data, yystack.l_mark[0].str))
			fatal_exit("out of memory adding local-data");
	}
break;
case 343:
#line 1574 "./util/configparser.y"
	{
		char* ptr;
		OUTYY(("P(server_local_data_ptr:%s)\n", yystack.l_mark[0].str));
		ptr = cfg_ptr_reverse(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if(ptr) {
			if(!cfg_strlist_insert(&cfg_parser->cfg->
				local_data, ptr))
				fatal_exit("out of memory adding local-data");
		} else {
			yyerror("local-data-ptr could not be reversed");
		}
	}
break;
case 344:
#line 1589 "./util/configparser.y"
	{
		OUTYY(("P(server_minimal_responses:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->minimal_responses =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 345:
#line 1599 "./util/configparser.y"
	{
		OUTYY(("P(server_rrset_roundrobin:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->rrset_roundrobin =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 346:
#line 1609 "./util/configparser.y"
	{
		OUTYY(("P(server_max_udp_size:%s)\n", yystack.l_mark[0].str));
		cfg_parser->cfg->max_udp_size = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 347:
#line 1616 "./util/configparser.y"
	{
		OUTYY(("P(dns64_prefix:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dns64_prefix);
		cfg_parser->cfg->dns64_prefix = yystack.l_mark[0].str;
	}
break;
case 348:
#line 1623 "./util/configparser.y"
	{
		OUTYY(("P(server_dns64_synthall:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dns64_synthall = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 349:
#line 1632 "./util/configparser.y"
	{
		char* p, *s = yystack.l_mark[0].str;
		OUTYY(("P(server_define_tag:%s)\n", yystack.l_mark[0].str));
		while((p=strsep(&s, " \t\n")) != NULL) {
			if(*p) {
				if(!config_add_tag(cfg_parser->cfg, p))
					yyerror("could not define-tag, "
						"out of memory");
			}
		}
		free(yystack.l_mark[0].str);
	}
break;
case 350:
#line 1646 "./util/configparser.y"
	{
		size_t len = 0;
		uint8_t* bitlist = config_parse_taglist(cfg_parser->cfg, yystack.l_mark[0].str,
			&len);
		free(yystack.l_mark[0].str);
		OUTYY(("P(server_local_zone_tag:%s)\n", yystack.l_mark[-1].str));
		if(!bitlist)
			yyerror("could not parse tags, (define-tag them first)");
		if(bitlist) {
			if(!cfg_strbytelist_insert(
				&cfg_parser->cfg->local_zone_tags,
				yystack.l_mark[-1].str, bitlist, len)) {
				yyerror("out of memory");
				free(yystack.l_mark[-1].str);
			}
		}
	}
break;
case 351:
#line 1665 "./util/configparser.y"
	{
		size_t len = 0;
		uint8_t* bitlist = config_parse_taglist(cfg_parser->cfg, yystack.l_mark[0].str,
			&len);
		free(yystack.l_mark[0].str);
		OUTYY(("P(server_access_control_tag:%s)\n", yystack.l_mark[-1].str));
		if(!bitlist)
			yyerror("could not parse tags, (define-tag them first)");
		if(bitlist) {
			if(!cfg_strbytelist_insert(
				&cfg_parser->cfg->acl_tags,
				yystack.l_mark[-1].str, bitlist, len)) {
				yyerror("out of memory");
				free(yystack.l_mark[-1].str);
			}
		}
	}
break;
case 352:
#line 1684 "./util/configparser.y"
	{
		OUTYY(("P(server_access_control_tag_action:%s %s %s)\n", yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str3list_insert(&cfg_parser->cfg->acl_tag_actions,
			yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-2].str);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 353:
#line 1696 "./util/configparser.y"
	{
		OUTYY(("P(server_access_control_tag_data:%s %s %s)\n", yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str3list_insert(&cfg_parser->cfg->acl_tag_datas,
			yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-2].str);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 354:
#line 1708 "./util/configparser.y"
	{
		OUTYY(("P(server_local_zone_override:%s %s %s)\n", yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str3list_insert(&cfg_parser->cfg->local_zone_overrides,
			yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-2].str);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 355:
#line 1720 "./util/configparser.y"
	{
		OUTYY(("P(server_access_control_view:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str2list_insert(&cfg_parser->cfg->acl_view,
			yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 356:
#line 1731 "./util/configparser.y"
	{
		size_t len = 0;
		uint8_t* bitlist = config_parse_taglist(cfg_parser->cfg, yystack.l_mark[0].str,
			&len);
		free(yystack.l_mark[0].str);
		OUTYY(("P(response_ip_tag:%s)\n", yystack.l_mark[-1].str));
		if(!bitlist)
			yyerror("could not parse tags, (define-tag them first)");
		if(bitlist) {
			if(!cfg_strbytelist_insert(
				&cfg_parser->cfg->respip_tags,
				yystack.l_mark[-1].str, bitlist, len)) {
				yyerror("out of memory");
				free(yystack.l_mark[-1].str);
			}
		}
	}
break;
case 357:
#line 1750 "./util/configparser.y"
	{ 
		OUTYY(("P(server_ip_ratelimit:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->ip_ratelimit = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 358:
#line 1760 "./util/configparser.y"
	{ 
		OUTYY(("P(server_ratelimit:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->ratelimit = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 359:
#line 1769 "./util/configparser.y"
	{
  	OUTYY(("P(server_ip_ratelimit_size:%s)\n", yystack.l_mark[0].str));
  	if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->ip_ratelimit_size))
  		yyerror("memory size expected");
  	free(yystack.l_mark[0].str);
  }
break;
case 360:
#line 1777 "./util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->ratelimit_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 361:
#line 1785 "./util/configparser.y"
	{
  	OUTYY(("P(server_ip_ratelimit_slabs:%s)\n", yystack.l_mark[0].str));
  	if(atoi(yystack.l_mark[0].str) == 0)
  		yyerror("number expected");
  	else {
  		cfg_parser->cfg->ip_ratelimit_slabs = atoi(yystack.l_mark[0].str);
  		if(!is_pow2(cfg_parser->cfg->ip_ratelimit_slabs))
  			yyerror("must be a power of 2");
  	}
  	free(yystack.l_mark[0].str);
  }
break;
case 362:
#line 1798 "./util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->ratelimit_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->ratelimit_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 363:
#line 1811 "./util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_for_domain:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0) {
			yyerror("number expected");
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->
				ratelimit_for_domain, yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding "
					"ratelimit-for-domain");
		}
	}
break;
case 364:
#line 1824 "./util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_below_domain:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0) {
			yyerror("number expected");
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->
				ratelimit_below_domain, yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding "
					"ratelimit-below-domain");
		}
	}
break;
case 365:
#line 1837 "./util/configparser.y"
	{ 
  	OUTYY(("P(server_ip_ratelimit_factor:%s)\n", yystack.l_mark[0].str)); 
  	if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
  		yyerror("number expected");
  	else cfg_parser->cfg->ip_ratelimit_factor = atoi(yystack.l_mark[0].str);
  	free(yystack.l_mark[0].str);
	}
break;
case 366:
#line 1846 "./util/configparser.y"
	{ 
		OUTYY(("P(server_ratelimit_factor:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->ratelimit_factor = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 367:
#line 1855 "./util/configparser.y"
	{
		OUTYY(("P(server_qname_minimisation:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->qname_minimisation = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 368:
#line 1865 "./util/configparser.y"
	{
		OUTYY(("P(server_qname_minimisation_strict:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->qname_minimisation_strict = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 369:
#line 1875 "./util/configparser.y"
	{
	#ifdef USE_IPSECMOD
		OUTYY(("P(server_ipsecmod_enabled:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ipsecmod_enabled = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	#else
		OUTYY(("P(Compiled without IPsec module, ignoring)\n"));
	#endif
	}
break;
case 370:
#line 1888 "./util/configparser.y"
	{
	#ifdef USE_IPSECMOD
		OUTYY(("P(server_ipsecmod_ignore_bogus:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ipsecmod_ignore_bogus = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	#else
		OUTYY(("P(Compiled without IPsec module, ignoring)\n"));
	#endif
	}
break;
case 371:
#line 1901 "./util/configparser.y"
	{
	#ifdef USE_IPSECMOD
		OUTYY(("P(server_ipsecmod_hook:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->ipsecmod_hook);
		cfg_parser->cfg->ipsecmod_hook = yystack.l_mark[0].str;
	#else
		OUTYY(("P(Compiled without IPsec module, ignoring)\n"));
	#endif
	}
break;
case 372:
#line 1912 "./util/configparser.y"
	{
	#ifdef USE_IPSECMOD
		OUTYY(("P(server_ipsecmod_max_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->ipsecmod_max_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	#else
		OUTYY(("P(Compiled without IPsec module, ignoring)\n"));
	#endif
	}
break;
case 373:
#line 1925 "./util/configparser.y"
	{
	#ifdef USE_IPSECMOD
		OUTYY(("P(server_ipsecmod_whitelist:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->ipsecmod_whitelist, yystack.l_mark[0].str))
			yyerror("out of memory");
	#else
		OUTYY(("P(Compiled without IPsec module, ignoring)\n"));
	#endif
	}
break;
case 374:
#line 1936 "./util/configparser.y"
	{
	#ifdef USE_IPSECMOD
		OUTYY(("P(server_ipsecmod_strict:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ipsecmod_strict = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	#else
		OUTYY(("P(Compiled without IPsec module, ignoring)\n"));
	#endif
	}
break;
case 375:
#line 1949 "./util/configparser.y"
	{
		OUTYY(("P(name:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->stubs->name)
			yyerror("stub name override, there must be one name "
				"for one stub-zone");
		free(cfg_parser->cfg->stubs->name);
		cfg_parser->cfg->stubs->name = yystack.l_mark[0].str;
	}
break;
case 376:
#line 1959 "./util/configparser.y"
	{
		OUTYY(("P(stub-host:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->stubs->hosts, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 377:
#line 1966 "./util/configparser.y"
	{
		OUTYY(("P(stub-addr:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->stubs->addrs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 378:
#line 1973 "./util/configparser.y"
	{
		OUTYY(("P(stub-first:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stubs->isfirst=(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 379:
#line 1982 "./util/configparser.y"
	{
		OUTYY(("P(stub-ssl-upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stubs->ssl_upstream = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 380:
#line 1992 "./util/configparser.y"
	{
		OUTYY(("P(stub-prime:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stubs->isprime = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 381:
#line 2002 "./util/configparser.y"
	{
		OUTYY(("P(name:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->forwards->name)
			yyerror("forward name override, there must be one "
				"name for one forward-zone");
		free(cfg_parser->cfg->forwards->name);
		cfg_parser->cfg->forwards->name = yystack.l_mark[0].str;
	}
break;
case 382:
#line 2012 "./util/configparser.y"
	{
		OUTYY(("P(forward-host:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->forwards->hosts, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 383:
#line 2019 "./util/configparser.y"
	{
		OUTYY(("P(forward-addr:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->forwards->addrs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 384:
#line 2026 "./util/configparser.y"
	{
		OUTYY(("P(forward-first:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->forwards->isfirst=(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 385:
#line 2035 "./util/configparser.y"
	{
		OUTYY(("P(forward-preference:%s)\n", yystack.l_mark[0].str));
		if (strcmp(yystack.l_mark[0].str, "only") == 0) {
			cfg_parser->cfg->forwards->preference = FORWARD_ONLY;
		} else if (strcmp(yystack.l_mark[0].str, "preferred") == 0) {
			cfg_parser->cfg->forwards->preference = FORWARD_PREFERRED;
		} else if (strcmp(yystack.l_mark[0].str, "backup") == 0) {
			cfg_parser->cfg->forwards->preference = FORWARD_BACKUP;
		} else {
			yyerror("expected only, preferred or backup.");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 386:
#line 2050 "./util/configparser.y"
	{
		OUTYY(("P(forward-ssl-upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->forwards->ssl_upstream = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 387:
#line 2060 "./util/configparser.y"
	{
		OUTYY(("P(name:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->auths->name)
			yyerror("auth name override, there must be one name "
				"for one auth-zone");
		free(cfg_parser->cfg->auths->name);
		cfg_parser->cfg->auths->name = yystack.l_mark[0].str;
	}
break;
case 388:
#line 2070 "./util/configparser.y"
	{
		OUTYY(("P(zonefile:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->auths->zonefile);
		cfg_parser->cfg->auths->zonefile = yystack.l_mark[0].str;
	}
break;
case 389:
#line 2077 "./util/configparser.y"
	{
		OUTYY(("P(master:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->auths->masters, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 390:
#line 2084 "./util/configparser.y"
	{
		OUTYY(("P(url:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->auths->urls, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 391:
#line 2091 "./util/configparser.y"
	{
		OUTYY(("P(for-downstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->auths->for_downstream =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 392:
#line 2101 "./util/configparser.y"
	{
		OUTYY(("P(for-upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->auths->for_upstream =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 393:
#line 2111 "./util/configparser.y"
	{
		OUTYY(("P(fallback-enabled:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->auths->fallback_enabled =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 394:
#line 2121 "./util/configparser.y"
	{
		OUTYY(("P(name:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->views->name)
			yyerror("view name override, there must be one "
				"name for one view");
		free(cfg_parser->cfg->views->name);
		cfg_parser->cfg->views->name = yystack.l_mark[0].str;
	}
break;
case 395:
#line 2131 "./util/configparser.y"
	{
		OUTYY(("P(view_local_zone:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "static")!=0 && strcmp(yystack.l_mark[0].str, "deny")!=0 &&
		   strcmp(yystack.l_mark[0].str, "refuse")!=0 && strcmp(yystack.l_mark[0].str, "redirect")!=0 &&
		   strcmp(yystack.l_mark[0].str, "transparent")!=0 && strcmp(yystack.l_mark[0].str, "nodefault")!=0
		   && strcmp(yystack.l_mark[0].str, "typetransparent")!=0
		   && strcmp(yystack.l_mark[0].str, "always_transparent")!=0
		   && strcmp(yystack.l_mark[0].str, "always_refuse")!=0
		   && strcmp(yystack.l_mark[0].str, "always_nxdomain")!=0
		   && strcmp(yystack.l_mark[0].str, "inform")!=0 && strcmp(yystack.l_mark[0].str, "inform_deny")!=0)
			yyerror("local-zone type: expected static, deny, "
				"refuse, redirect, transparent, "
				"typetransparent, inform, inform_deny, "
				"always_transparent, always_refuse, "
				"always_nxdomain or nodefault");
		else if(strcmp(yystack.l_mark[0].str, "nodefault")==0) {
			if(!cfg_strlist_insert(&cfg_parser->cfg->views->
				local_zones_nodefault, yystack.l_mark[-1].str))
				fatal_exit("out of memory adding local-zone");
			free(yystack.l_mark[0].str);
		} else {
			if(!cfg_str2list_insert(
				&cfg_parser->cfg->views->local_zones, 
				yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding local-zone");
		}
	}
break;
case 396:
#line 2160 "./util/configparser.y"
	{
		OUTYY(("P(view_response_ip:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		validate_respip_action(yystack.l_mark[0].str);
		if(!cfg_str2list_insert(
			&cfg_parser->cfg->views->respip_actions, yystack.l_mark[-1].str, yystack.l_mark[0].str))
			fatal_exit("out of memory adding per-view "
				"response-ip action");
	}
break;
case 397:
#line 2170 "./util/configparser.y"
	{
		OUTYY(("P(view_response_ip_data:%s)\n", yystack.l_mark[-1].str));
		if(!cfg_str2list_insert(
			&cfg_parser->cfg->views->respip_data, yystack.l_mark[-1].str, yystack.l_mark[0].str))
			fatal_exit("out of memory adding response-ip-data");
	}
break;
case 398:
#line 2178 "./util/configparser.y"
	{
		OUTYY(("P(view_local_data:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->views->local_data, yystack.l_mark[0].str)) {
			fatal_exit("out of memory adding local-data");
			free(yystack.l_mark[0].str);
		}
	}
break;
case 399:
#line 2187 "./util/configparser.y"
	{
		char* ptr;
		OUTYY(("P(view_local_data_ptr:%s)\n", yystack.l_mark[0].str));
		ptr = cfg_ptr_reverse(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if(ptr) {
			if(!cfg_strlist_insert(&cfg_parser->cfg->views->
				local_data, ptr))
				fatal_exit("out of memory adding local-data");
		} else {
			yyerror("local-data-ptr could not be reversed");
		}
	}
break;
case 400:
#line 2202 "./util/configparser.y"
	{
		OUTYY(("P(view-first:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->views->isfirst=(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 401:
#line 2211 "./util/configparser.y"
	{ 
		OUTYY(("\nP(remote-control:)\n")); 
	}
break;
case 412:
#line 2222 "./util/configparser.y"
	{
		OUTYY(("P(control_enable:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->remote_control_enable = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 413:
#line 2232 "./util/configparser.y"
	{
		OUTYY(("P(control_port:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("control port number expected");
		else cfg_parser->cfg->control_port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 414:
#line 2241 "./util/configparser.y"
	{
		OUTYY(("P(control_interface:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->control_ifs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 415:
#line 2248 "./util/configparser.y"
	{
		OUTYY(("P(control_use_cert:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->remote_control_use_cert =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 416:
#line 2258 "./util/configparser.y"
	{
		OUTYY(("P(rc_server_key_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->server_key_file);
		cfg_parser->cfg->server_key_file = yystack.l_mark[0].str;
	}
break;
case 417:
#line 2265 "./util/configparser.y"
	{
		OUTYY(("P(rc_server_cert_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->server_cert_file);
		cfg_parser->cfg->server_cert_file = yystack.l_mark[0].str;
	}
break;
case 418:
#line 2272 "./util/configparser.y"
	{
		OUTYY(("P(rc_control_key_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->control_key_file);
		cfg_parser->cfg->control_key_file = yystack.l_mark[0].str;
	}
break;
case 419:
#line 2279 "./util/configparser.y"
	{
		OUTYY(("P(rc_control_cert_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->control_cert_file);
		cfg_parser->cfg->control_cert_file = yystack.l_mark[0].str;
	}
break;
case 420:
#line 2286 "./util/configparser.y"
	{
		OUTYY(("\nP(dnstap:)\n"));
	}
break;
case 435:
#line 2303 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_enable:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap = (strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 436:
#line 2311 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_socket_path:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnstap_socket_path);
		cfg_parser->cfg->dnstap_socket_path = yystack.l_mark[0].str;
	}
break;
case 437:
#line 2318 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_send_identity:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_send_identity = (strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 438:
#line 2326 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_send_version:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_send_version = (strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 439:
#line 2334 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_identity:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnstap_identity);
		cfg_parser->cfg->dnstap_identity = yystack.l_mark[0].str;
	}
break;
case 440:
#line 2341 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_version:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnstap_version);
		cfg_parser->cfg->dnstap_version = yystack.l_mark[0].str;
	}
break;
case 441:
#line 2348 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_resolver_query_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_resolver_query_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 442:
#line 2357 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_resolver_response_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_resolver_response_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 443:
#line 2366 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_client_query_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_client_query_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 444:
#line 2375 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_client_response_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_client_response_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 445:
#line 2384 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_forwarder_query_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_forwarder_query_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 446:
#line 2393 "./util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_forwarder_response_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_forwarder_response_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 447:
#line 2402 "./util/configparser.y"
	{ 
		OUTYY(("\nP(python:)\n")); 
	}
break;
case 451:
#line 2411 "./util/configparser.y"
	{
		OUTYY(("P(python-script:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->python_script);
		cfg_parser->cfg->python_script = yystack.l_mark[0].str;
	}
break;
case 452:
#line 2417 "./util/configparser.y"
	{
		OUTYY(("P(disable_dnssec_lame_check:%s)\n", yystack.l_mark[0].str));
		if (strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->disable_dnssec_lame_check =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 453:
#line 2427 "./util/configparser.y"
	{
		OUTYY(("P(server_log_identity:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->log_identity);
		cfg_parser->cfg->log_identity = yystack.l_mark[0].str;
	}
break;
case 454:
#line 2434 "./util/configparser.y"
	{
		OUTYY(("P(server_response_ip:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		validate_respip_action(yystack.l_mark[0].str);
		if(!cfg_str2list_insert(&cfg_parser->cfg->respip_actions,
			yystack.l_mark[-1].str, yystack.l_mark[0].str))
			fatal_exit("out of memory adding response-ip");
	}
break;
case 455:
#line 2443 "./util/configparser.y"
	{
		OUTYY(("P(server_response_ip_data:%s)\n", yystack.l_mark[-1].str));
			if(!cfg_str2list_insert(&cfg_parser->cfg->respip_data,
				yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding response-ip-data");
	}
break;
case 456:
#line 2451 "./util/configparser.y"
	{
		OUTYY(("\nP(dnscrypt:)\n"));
		OUTYY(("\nP(dnscrypt:)\n"));
	}
break;
case 469:
#line 2468 "./util/configparser.y"
	{
		OUTYY(("P(dnsc_dnscrypt_enable:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnscrypt = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 470:
#line 2478 "./util/configparser.y"
	{
		OUTYY(("P(dnsc_dnscrypt_port:%s)\n", yystack.l_mark[0].str));

		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("port number expected");
		else cfg_parser->cfg->dnscrypt_port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 471:
#line 2488 "./util/configparser.y"
	{
		OUTYY(("P(dnsc_dnscrypt_provider:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnscrypt_provider);
		cfg_parser->cfg->dnscrypt_provider = yystack.l_mark[0].str;
	}
break;
case 472:
#line 2495 "./util/configparser.y"
	{
		OUTYY(("P(dnsc_dnscrypt_provider_cert:%s)\n", yystack.l_mark[0].str));
		if(cfg_strlist_find(cfg_parser->cfg->dnscrypt_provider_cert, yystack.l_mark[0].str))
			log_warn("dnscrypt-provider-cert %s is a duplicate", yystack.l_mark[0].str);
		if(!cfg_strlist_insert(&cfg_parser->cfg->dnscrypt_provider_cert, yystack.l_mark[0].str))
			fatal_exit("out of memory adding dnscrypt-provider-cert");
	}
break;
case 473:
#line 2504 "./util/configparser.y"
	{
		OUTYY(("P(dnsc_dnscrypt_provider_cert_rotated:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->dnscrypt_provider_cert_rotated, yystack.l_mark[0].str))
			fatal_exit("out of memory adding dnscrypt-provider-cert-rotated");
	}
break;
case 474:
#line 2511 "./util/configparser.y"
	{
		OUTYY(("P(dnsc_dnscrypt_secret_key:%s)\n", yystack.l_mark[0].str));
		if(cfg_strlist_find(cfg_parser->cfg->dnscrypt_secret_key, yystack.l_mark[0].str))
			log_warn("dnscrypt-secret-key: %s is a duplicate", yystack.l_mark[0].str);
		if(!cfg_strlist_insert(&cfg_parser->cfg->dnscrypt_secret_key, yystack.l_mark[0].str))
			fatal_exit("out of memory adding dnscrypt-secret-key");
	}
break;
case 475:
#line 2520 "./util/configparser.y"
	{
  	OUTYY(("P(dnscrypt_shared_secret_cache_size:%s)\n", yystack.l_mark[0].str));
  	if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->dnscrypt_shared_secret_cache_size))
  		yyerror("memory size expected");
  	free(yystack.l_mark[0].str);
  }
break;
case 476:
#line 2528 "./util/configparser.y"
	{
  	OUTYY(("P(dnscrypt_shared_secret_cache_slabs:%s)\n", yystack.l_mark[0].str));
  	if(atoi(yystack.l_mark[0].str) == 0)
  		yyerror("number expected");
  	else {
  		cfg_parser->cfg->dnscrypt_shared_secret_cache_slabs = atoi(yystack.l_mark[0].str);
  		if(!is_pow2(cfg_parser->cfg->dnscrypt_shared_secret_cache_slabs))
  			yyerror("must be a power of 2");
  	}
  	free(yystack.l_mark[0].str);
  }
break;
case 477:
#line 2541 "./util/configparser.y"
	{
  	OUTYY(("P(dnscrypt_nonce_cache_size:%s)\n", yystack.l_mark[0].str));
  	if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->dnscrypt_nonce_cache_size))
  		yyerror("memory size expected");
  	free(yystack.l_mark[0].str);
  }
break;
case 478:
#line 2549 "./util/configparser.y"
	{
  	OUTYY(("P(dnscrypt_nonce_cache_slabs:%s)\n", yystack.l_mark[0].str));
  	if(atoi(yystack.l_mark[0].str) == 0)
  		yyerror("number expected");
  	else {
  		cfg_parser->cfg->dnscrypt_nonce_cache_slabs = atoi(yystack.l_mark[0].str);
  		if(!is_pow2(cfg_parser->cfg->dnscrypt_nonce_cache_slabs))
  			yyerror("must be a power of 2");
  	}
  	free(yystack.l_mark[0].str);
  }
break;
case 479:
#line 2562 "./util/configparser.y"
	{
		OUTYY(("\nP(cachedb:)\n"));
	}
break;
case 484:
#line 2571 "./util/configparser.y"
	{
	#ifdef USE_CACHEDB
		OUTYY(("P(backend:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->cachedb_backend)
			yyerror("cachedb backend override, there must be one "
				"backend");
		free(cfg_parser->cfg->cachedb_backend);
		cfg_parser->cfg->cachedb_backend = yystack.l_mark[0].str;
	#else
		OUTYY(("P(Compiled without cachedb, ignoring)\n"));
	#endif
	}
break;
case 485:
#line 2585 "./util/configparser.y"
	{
	#ifdef USE_CACHEDB
		OUTYY(("P(secret-seed:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->cachedb_secret)
			yyerror("cachedb secret-seed override, there must be "
				"only one secret");
		free(cfg_parser->cfg->cachedb_secret);
		cfg_parser->cfg->cachedb_secret = yystack.l_mark[0].str;
	#else
		OUTYY(("P(Compiled without cachedb, ignoring)\n"));
		free(yystack.l_mark[0].str);
	#endif
	}
break;
#line 4243 "util/configparser.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
