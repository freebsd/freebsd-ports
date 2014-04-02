# Created by: janek
# $FreeBSD$

PORTNAME=	x3270
PORTVERSION=	3.3.13
CATEGORIES=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/current/
EXTRACT_SUFX=	ga7-src.tgz

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	3270 Terminal emulator

# Conflict due to x3270if
CONFLICTS=	c3270-*

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		iconv imake:env
USE_XORG=	ice sm x11 xaw xext xmu xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-fontdir=${PREFIX}/lib/X11/fonts/local --disable-dbcs
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib"
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USE_OPENSSL=	yes
.endif
MAKE_ARGS+=	COMPRESSMANCMD="${DO_NADA}" \
		INSTALL="${INSTALL}" INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} ${_BINOWNGRP} -m ${BINMODE}" \
		INSTBINFLAGS="${_BINOWNGRP} -m ${BINMODE}" \
		INSTDATFLAGS="${_SHROWNGRP} -m ${SHAREMODE}" \
		INSTMANFLAGS="${_MANOWNGRP} -m ${MANMODE}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

PORTDOCS=	README README.dbcs
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|\$$(INSTALL) -c|$$(INSTALL) $$(INSTALLFLAGS)|g' \
		${WRKSRC}/Imakefile.in

post-install:
.for m in x3270-script.man x3270.man x3270if.man
	@(cd ${WRKSRC} ; ${INSTALL_MAN} ${m} ${STAGEDIR}${MAN1PREFIX}/man/man1/)
.endfor
	${INSTALL_MAN} ${WRKSRC}/ibm_hosts.man ${STAGEDIR}${MAN5PREFIX}/man/man5/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@(cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
