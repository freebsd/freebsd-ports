# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.171 2012/10/01 16:19:07 kwm Exp $

PORTNAME=	yelp
PORTVERSION=	2.30.2
PORTREVISION=	7
CATEGORIES=	x11 gnome
MASTER_SITES=	LOCAL/kwm
DISTNAME=	${PORTNAME}-webkit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		startup-notification-1:${PORTSDIR}/x11/startup-notification \
		webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2 \
		rarian:${PORTSDIR}/textproc/rarian

CONFLICTS=	yelp-3.[0-9]*

USES=		desktop-file-utils gettext gmake pkgconfig
USE_BZIP2=	yes
USE_XORG=	ice
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	yelp.schemas

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

post-extract:
	${RM} -f ${WRKSRC}/data/yelp.schemas

post-patch:
	@${REINPLACE_CMD} -e 's,[-/]unstable,,' \
		-e 's/ --define-variable=includetype=unstable//' \
		${WRKSRC}/configure

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
