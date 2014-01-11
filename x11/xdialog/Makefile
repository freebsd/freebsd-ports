# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	xdialog
PORTVERSION=	2.3.1
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://xdialog.free.fr/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A drop in replacement for the "dialog" or "cdialog" programs

USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(.PARSEDIR)
USES=		gmake
.endif

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MNLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|m4 lib src|m4 src|g ; \
		 s|-I../lib||g ; \
		 s|-L../lib -lgetopt||g ; \
		 s| install-docDATA||g'
	@${REINPLACE_CMD} -e 's,Xdialog\\-%%version%%,xdialog,' \
		${WRKSRC}/doc/Xdialog.man

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/samples
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${DOCSDIR}/samples
.endif

.include <bsd.port.mk>
