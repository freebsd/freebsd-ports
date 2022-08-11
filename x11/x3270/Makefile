PORTNAME?=	x3270
PORTVERSION=	4.2
CATEGORIES?=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/04.02/
DISTFILES=	suite3270-${PORTVERSION}ga4-src.tgz

MAINTAINER=	kbowling@FreeBSD.org
COMMENT?=	3270 Terminal emulator

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	tclsh:lang/tcl-wrapper
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe iconv gmake readline shebangfix tcl

# x3270 includes c3270
CONFLICTS_INSTALL?=	c3270

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-unix
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-tls
.else
USES+=	ssl
.endif

CPE_VENDOR=	paul_mattes

WRKSRC=		${WRKDIR}/suite3270-${PORTVERSION}

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES DBCS

DBCS_DESC=	EBCDIC double-byte character set support

.include <bsd.port.options.mk>

.if ! defined(C3270)
BUILD_DEPENDS+=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale:x11-fonts/mkfontscale
USES+=	fonts xorg
USE_XORG=	ice sm x11 xaw xext xmu xt xorgproto
CONFIGURE_ARGS+=	--with-fontdir=${FONTSDIR} \
			--with-x=${LOCALBASE}
SHEBANG_FILES=	x3270/x3270a.in
PLIST_SUB+=	X3270=""
.else
CONFIGURE_ARGS+=	--disable-x3270 \
			--disable-x3270if
PLIST_SUB+=	X3270="@comment "
.endif

# EBCDIC double-byte character set support is disabled by default
.if ${PORT_OPTIONS:DBCS}
CONFIGURE_ARGS+=	--enable-dbcs
PLIST_SUB+=	DBCS=""
.else
PLIST_SUB+=	DBCS="@comment "
.endif

post-install:
.for m in b3270 c3270 pr3287 s3270 tcl3270
	@(cd ${WRKSRC} ; ${INSTALL_MAN} ${m}/${m}.man ${STAGEDIR}${MAN1PREFIX}/man/man1/${m}.1)
.endfor
.if ! defined(C3270)
	${INSTALL_MAN} ${WRKSRC}/x3270/x3270.man ${STAGEDIR}${MAN5PREFIX}/man/man1/x3270.1
	${INSTALL_MAN} ${WRKSRC}/x3270if/x3270if.man ${STAGEDIR}${MAN5PREFIX}/man/man1/x3270if.1
.endif
	${INSTALL_MAN} ${WRKSRC}/c3270/ibm_hosts.man ${STAGEDIR}${MAN5PREFIX}/man/man5/ibm_hosts.5

	@(cd ${WRKSRC}/x3270/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC}/x3270 && ${COPYTREE_SHARE} html ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
