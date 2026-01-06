PORTNAME?=	x3270
PORTVERSION=	4.5
CATEGORIES?=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/04.05/
DISTFILES=	suite3270-${PORTVERSION}ga5-src.tgz

MAINTAINER=	kbowling@FreeBSD.org
COMMENT?=	3270 Terminal emulator
WWW=		https://x3270.miraheze.org/wiki/Main_Page

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	tclsh:lang/tcl-wrapper
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=			cpe gmake iconv python:build readline shebangfix tcl
CPE_VENDOR=		paul_mattes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-unix
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-tls
.else
USES+=			ssl
.endif

# x3270 includes c3270
CONFLICTS_INSTALL?=	c3270

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/suite3270-${PORTVERSION}

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DBCS DOCS EXAMPLES
OPTIONS_SUB=	yes

DBCS_DESC=		EBCDIC double-byte character set support
DBCS_CONFIGURE_ENABLE=	dbcs
DBCS_PLIST_SUB=		DBCS=""

.if !defined(C3270)
BUILD_DEPENDS+=		bdftopcf:x11-fonts/bdftopcf \
			mkfontscale:x11-fonts/mkfontscale
USES+=			fonts xorg
USE_XORG=		ice sm x11 xaw xext xmu xorgproto xt
CONFIGURE_ARGS+=	--with-fontdir=${FONTSDIR} \
			--with-x=${LOCALBASE}
SHEBANG_FILES=		x3270/x3270a.in
PLIST_SUB+=		X3270=""
.else
CONFIGURE_ARGS+=	--disable-x3270 \
			--disable-x3270if
PLIST_SUB+=		X3270="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|#!/usr/bin/env python3|#!${PYTHON_CMD}|' \
		${WRKSRC}/Common/mkversion.py

post-install:
.for m in b3270 c3270 pr3287 s3270 tcl3270
	@(cd ${WRKSRC} ; ${INSTALL_MAN} ${m}/${m}.man ${STAGEDIR}${PREFIX}/share/man/man1/${m}.1)
.endfor
.if !defined(C3270)
	${INSTALL_MAN} ${WRKSRC}/x3270/x3270.man ${STAGEDIR}${PREFIX}/share/man/man1/x3270.1
	${INSTALL_MAN} ${WRKSRC}/x3270if/x3270if.man ${STAGEDIR}${PREFIX}/share/man/man1/x3270if.1
.endif
	${INSTALL_MAN} ${WRKSRC}/ibm_hosts/ibm_hosts.man ${STAGEDIR}${PREFIX}/share/man/man5/ibm_hosts.5

	@(cd ${WRKSRC}/x3270/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC}/x3270 && ${COPYTREE_SHARE} html ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
