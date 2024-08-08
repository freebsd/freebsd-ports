PORTNAME=	3ddesktop
PORTVERSION=	0.2.9
PORTREVISION=	18
CATEGORIES=	x11
MASTER_SITES=	SF/desk3d/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Virtual Desktop Switcher
WWW=		https://desk3d.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		gl localbase pkgconfig xorg
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xext xi xmu xt xxf86vm

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CPPFLAGS+=	-DHAVE_DECL_GETOPT -pthread
LDFLAGS+=	-pthread

PLIST_FILES=	bin/3ddesk \
		bin/3ddeskd \
		etc/3ddesktop.conf \
		share/man/man1/3ddesk.1.gz \
		share/man/man1/3ddeskd.1.gz
PORTDATA=	digits.bmp
PORTDOCS=	README README.windowmanagers

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O3||g ; \
		 s|@ACLOCAL@|${TRUE}|g ; \
		 s|@AUTOCONF@|${TRUE}|g ; \
		 s|@AUTOHEADER@|${TRUE}|g ; \
		 s|@AUTOMAKE@|${TRUE}|g'

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README README.windowmanagers
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
