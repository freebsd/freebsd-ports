# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	gmrun
PORTVERSION=	0.9.2
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Customizable program to run programs, with tab-completion

LIB_DEPENDS=	libpopt.so:devel/popt

OPTIONS_DEFINE=	DOCS

USES=		gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-stlport

PORTDOCS=	README
PLIST_FILES=	bin/gmrun %%DATADIR%%/gmrunrc

post-patch:
	@${REINPLACE_CMD} -e '/my_alphasort/s#const void\*#const struct dirent**#g' \
		${WRKSRC}/src/gtkcompletionline.cc

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
