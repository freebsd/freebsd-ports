# Created by: janek
# $FreeBSD$

PORTNAME=	x3270
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/04.00/
DISTFILES=	suite3270-${PORTVERSION}ga12-src.tgz

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	3270 Terminal emulator

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale:x11-fonts/mkfontscale \
		tclsh:lang/tcl-wrapper
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe iconv fonts gmake readline shebangfix tcl xorg
USE_XORG=	ice sm x11 xaw xext xmu xt xorgproto

# Conflict due to x3270if
CONFLICTS=	c3270-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontdir=${FONTSDIR} \
		--disable-dbcs \
		--with-x=${LOCALBASE} \
		--enable-unix \
		--enable-c3270
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USES+=	ssl
.endif

CPE_VENDOR=	paul_mattes

WRKSRC=		${WRKDIR}/suite3270-${PORTVERSION}

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

SHEBANG_FILES=	x3270/x3270a.in

post-install:
.for m in b3270/b3270.man c3270/c3270.man pr3287/pr3287.man s3270/s3270.man \
    tcl3270/tcl3270.man x3270/x3270-script.man x3270/x3270.man \
    x3270if/x3270if.man
	@(cd ${WRKSRC} ; ${INSTALL_MAN} ${m} ${STAGEDIR}${MAN1PREFIX}/man/man1/)
.endfor
	${INSTALL_MAN} ${WRKSRC}/c3270/ibm_hosts.man ${STAGEDIR}${MAN5PREFIX}/man/man5/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x3270/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x3270/README.dbcs ${STAGEDIR}${DOCSDIR}

	@(cd ${WRKSRC}/x3270/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC}/x3270 && ${COPYTREE_SHARE} html ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
