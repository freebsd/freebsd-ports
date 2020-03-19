# Created by: janek
# $FreeBSD$

PORTNAME=	x3270
PORTVERSION=	3.6
CATEGORIES=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/03.06/
DISTFILES=	suite3270-${PORTVERSION}ga8-src.tgz

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	3270 Terminal emulator

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale:x11-fonts/mkfontscale \
		tclsh:lang/tcl-wrapper

USES=		cpe iconv fonts gmake readline tcl xorg
USE_XORG=	ice sm x11 xaw xext xmu xt xorgproto

# Conflict due to x3270if
CONFLICTS=	c3270-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontdir=${FONTSDIR} \
		--disable-dbcs \
		--with-x=${LOCALBASE} \
		ac_cv_search_libiconv=${ICONV_LIB}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USES+=	ssl
.endif
MAKE_ARGS+=	COMPRESSMANCMD="${DO_NADA}" \
		INSTALL="${INSTALL}" INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} -m ${BINMODE}" \
		INSTBINFLAGS="-m ${BINMODE}" \
		INSTDATFLAGS="-m ${SHAREMODE}" \
		INSTMANFLAGS="-m ${MANMODE}"

CPE_VENDOR=	paul_mattes

WRKSRC=		${WRKDIR}/suite3270-${PORTVERSION}

#PORTDOCS=	x3270/README x3270/README.dbcs
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
.for m in x3270/x3270-script.man x3270/x3270.man s3270/x3270if.man
	@(cd ${WRKSRC} ; ${INSTALL_MAN} ${m} ${STAGEDIR}${MAN1PREFIX}/man/man1/)
.endfor
	${INSTALL_MAN} ${WRKSRC}/c3270/ibm_hosts.man ${STAGEDIR}${MAN5PREFIX}/man/man5/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x3270/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x3270/README.dbcs ${STAGEDIR}${DOCSDIR}

	@(cd ${WRKSRC}/x3270/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC}/x3270 && ${COPYTREE_SHARE} html ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
