# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The wxWindows GUI toolkit with GTK+ bindings (unstable version)

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-opengl
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include \
			  -I${LOCALBASE}/include \
			  -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv \
			 -L${X11BASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
.else
USE_GNOME=	gtk12
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=--enable-gtk2 ${MACHINE_ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_ARGS+=--host=${CONFIGURE_TARGET} --build=${CONFIGURE_TARGET}
.endif

pre-everything:
.if !defined(WITH_GTK2)
	@${ECHO_MSG} "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	@${ECHO_MSG} "You can define WITH_GTK2=yes if you want to use Gtk20 toolkit."
	@${ECHO_MSG} "This is marked as experimental by wxGTK authors."
	@${ECHO_MSG} "Note: applications already linked to Gtk12 wxGTK will no longer work."
	@${ECHO_MSG} "      You have to rebuild them by hand."
	@${ECHO_MSG} "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
.endif

pre-patch:
.if defined(WITH_GTK2)
	@${REINPLACE_CMD} -e 's|lgdk|lgdk-x11-2.0|g' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e 's|lgdk|lgdk12|g' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
